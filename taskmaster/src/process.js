const fs = require('fs');
var startProcess = require("./utils/startProcess");
var getStateInt = require("./utils/getStateInt");
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

      this.out = 1;
      this.err = 2;

    //   this.out = fs.openSync(config["stdout"], 'a');
    //   this.err = fs.openSync(config["stderr"], 'a');

      this.state = "STOPPED";
      this.stateInt = getStateInt("STOPPED");
    }

    start()
    {
        this.updateState("STARTING");
        startProcess(this, function(res) {
            if (res.status === "RUNNING")
            {
                this.pid = res.payload.pid;
                this.ppid = res.payload.ppid;
                this.updateState("RUNNING");
            }
            if (res.status === "EXITED")
            {
                this.updateState("EXITED");
                this.reload(res.payload);
            }
        }.bind(this));
    }

    reload(payload)
    {
        let code = payload.code;
        let signal = payload.signal;

        switch (this.autorestart) {
            case true:
              console.log('Restart ' + this.name);
              break;
            case false:
                break;
            case "unexpected":
                if (isExitCodesValid(this.exitcodes, code) === false)
                    console.log(`Not OK :  ${code} is not part of ` + this.exitcodes + ' -> reboot');
                else
                    console.log(`exit name : ${this.name} wide code : ${code}`);
              break;
            default:
                console.log(`exit name : ${this.name} wide code : ${code}`);
          }
    }

    updateState(state)
    {
        this.state = state;
        this.stateInt = getStateInt(state);
    }
}