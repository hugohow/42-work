const fs = require('fs');

module.exports = class Process {
    constructor(name, config, state) {
      this.name = name;
      this.config = config;

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

      this.state = state;
      this.stateInt = this.getStateInt(state);
    }


    getStateInt(state)
    {
        switch(state)
        {
            case "STOPPED":
                return 0;
            case "STARTING":
                return 10;
            case "RUNNING":
                return 20;
            case "BACKOFF":
                return 30;
            case "STOPPING":
                return 40;
            case "EXITED":
                return 100;
            case "FATAL":
                return 200;
            default:
                return 1000;
        }
    }
  }