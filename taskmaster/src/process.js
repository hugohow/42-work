const fs = require('fs');
var startProcess = require("./utils/startProcess");
var getStateInt = require("./utils/getStateInt");
var getComm = require("./utils/getComm");
var isExitCodesValid = require("./utils/isExitCodesValid");


module.exports = class Process {
    constructor(name, config) {
      this.name = name;
      this.config = config;

      this.pid = null;
      this.ppid = null;
      this.numprocs = config["numprocs"] ? parseInt(config["numprocs"]) : 1;
        
      this.exitcodes = config["exitcodes"] ? config["exitcodes"] : [0, 2];
      this.autorestart = config["autorestart"] ? config["autorestart"] : "unexpected";
      this.autostart = config["autostart"] ? config["autostart"] : true;
      this.cwd = config["workingdir"] ? config["workingdir"] : null;
      this.killSignal = config["stopsignal"] ? config["stopsignal"] : 'SIGTERM';
      this.env = config["env"] ? config["env"] : null;
     
      this.umask = config["umask"] ? config["umask"] : "022"

      this.startRetries = config["startretries"] ? config["startretries"] : 3;
      this.tries = 0;
      this.startTime = config["starttime"] ? config["starttime"] * 1000 : 1 * 1000;
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

    start()
    {
        this.tries++;
        this.updateState("STARTING");
        startProcess(this, function(res) {
            if (res.state === "RUNNING")
            {
                this.updateState("RUNNING");
                this.pid = res.payload.pid;
                this.ppid = res.payload.ppid;
            } 
            else if (res.state === "EXITED" || res.state === "BACKOFF")
            {
                this.updateState(res.state);
                if (this.isReloadable(res.payload) === true)
                    this.start();
            }
        }.bind(this));
    }

    isReloadable(payload)
    {
        let code = payload.code;
        
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