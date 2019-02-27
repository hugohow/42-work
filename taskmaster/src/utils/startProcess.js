const { spawn } = require('child_process');

module.exports = function startProcess(proc, callback) {
    let state;
    let timer;
    state = "STARTING";
    let child = spawn("sleep 2", [], {
        detached: true,
        stdio: ['ignore', proc.out, proc.err],
        env: proc.env,
        cwd: proc.cwd,
        killSignal: proc.killSignal,
        shell: true,
        unmask: proc.unmask
      });
      child.on('exit', function (code, signal) {
        clearTimeout(timer);
        console.log("signal "+ signal)
        if (signal)
        {
            callback({
                state: "STOPPED", 
                payload: {
                      pid: child.pid,
                      ppid: process.ppid,
                      code: code,
                      signal: signal,
                      spawn: child
                  }
              });
        }
        else
        {
            callback({
                state: state === "STARTING" ? "BACKOFF" : "EXITED", 
                payload: {
                      pid: child.pid,
                      ppid: process.ppid,
                      code: code,
                      signal: signal,
                      spawn: child
                  }
              });
        }
      });
      child.unref();
      timer = setTimeout(function(){
            state = "RUNNING";
            callback({
                state: "RUNNING", 
                payload: {
                    pid: child.pid,
                    ppid: process.ppid,
                    spawn: child
                }
            });
      }, proc.startTime);
}