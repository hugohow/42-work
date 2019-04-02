const fs = require('fs');
var startProcess = require("./utils/startProcess");
var getStateInt = require("./utils/getStateInt");
var getComm = require("./utils/getComm");
var isExitCodesValid = require("./utils/isExitCodesValid");
var getKillSignal = require("./utils/getKillSignal");

module.exports = class Process {
    constructor(name, config) {
      this.name = name;
      this.config = config;
      this.cmd = config["cmd"] ? config["cmd"] : " ";
      this.pid = null;
      this.ppid = null;
      this.spawn = null;
      this.numprocs = config["numprocs"] ? parseInt(config["numprocs"]) : 1;
        
      this.exitcodes = config["exitcodes"] ? config["exitcodes"] : [0, 2];
      this.autorestart = config["autorestart"] ? config["autorestart"] : "unexpected";
      this.autostart = config["autostart"] ? config["autostart"] : true;
      this.cwd = config["workingdir"] ? config["workingdir"] : null;
      this.killSignal = getKillSignal(config["stopsignal"]);
    //   console.log(getKillSignal(config["stopsignal"]));
      this.env = config["env"] ? config["env"] : null;
     
      this.umask = config["umask"] ? config["umask"] : "022"

      this.startRetries = config["startretries"] ? config["startretries"] : 3;
      this.tries = 0;
      this.startTime = config["starttime"] ? config["starttime"] * 1000 : 1 * 1000;

      this.stopTime = config["stoptime"] ? config["stoptime"] * 1000 : 10 * 1000;
      this.out = 1;
      this.err = 2;

    //   this.out = fs.openSync(config["stdout"], 'a');
    //   this.err = fs.openSync(config["stderr"], 'a');

      this.state = "STOPPED";
      this.stateInt = getStateInt("STOPPED");
      this.comment = getComm(this);

      if (this.autostart)
          this.start();
    }

    stop()
    {
        if (this.state === "EXITED" || this.state === "FATAL")
            return ;
        if (this.state === "BACKOFF")
            this.updateState("STOPPED");
        if (this.spawn)
        {

            this.updateState("STOPPING");
            this.spawn.kill(this.killSignal);
            var that = this;
            setTimeout(function(){
                if (that.state !== "STOPPED")
                {
                    that.spawn.kill("SIGKILL");
                    that.updateState("STOPPED");
                }
            }, this.stopTime);
        }
        else
        {
            console.log(`FAILED: attempted to kill process with sig ${this.killSignal} but it wasn't running`);
        }
    }

    start()
    {
        this.tries++;
        this.updateState("STARTING");
        startProcess(this, function(res) {
            if (res.state === "RUNNING")
            {
                this.pid = res.payload.pid;
                this.ppid = res.payload.ppid;
                this.spawn = res.payload.spawn;
                this.updateState("RUNNING");
            }
            else if (res.state === "EXITED" || res.state === "BACKOFF")
            {
                this.updateState(res.state);
                if (this.isReloadable(res.payload) === true)
                    this.start();
            }
            else if (res.state === "STOPPED")
            {
                this.updateState(res.state);
            }
        }.bind(this));
    }

    isReloadable(payload)
    {
        let code = payload.code;
        if (this.state === "STOPPING" || this.state === "STOPPED")
            return false;
        if (this.state === "BACKOFF")
        {
            if (this.tries === this.startRetries)
            {
                this.updateState("FATAL");
                return false;
            }
            return true;
        }
        if (this.state === "EXITED")
        {
            switch (this.autorestart) {
                case "unexpected":
                    if (isExitCodesValid(this.exitcodes, code) === false)
                        return true;
                    else
                        return false;
                default:
                    return this.autorestart === true;   
              }
        }
    }

    updateState(state)
    {
        console.log(`${this.name} changed state from ${this.state} to ${state}`);
        this.state = state;
        this.stateInt = getStateInt(state);
        this.comment = getComm(this);
    }
}