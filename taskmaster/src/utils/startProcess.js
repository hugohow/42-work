const { spawn } = require('child_process');

module.exports = function startProcess(proc, callback) {
    let child = spawn("ls", [], {
        detached: true,
        stdio: ['ignore', proc.out, proc.err],
        env: proc.env,
        cwd: proc.cwd,
        killSignal: proc.killSignal
      });
      child.on('exit', function (code, signal) {
        callback({
            status: "EXITED", 
            payload: {
                  pid: child.pid,
                  ppid: process.ppid,
                  code: code,
                  signal: signal
              }
          });
      });
      child.unref();
      callback({
          status: "RUNNING", 
          payload: {
                pid: child.pid,
                ppid: process.ppid
            }
        });
}