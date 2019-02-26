var net = require("net");
const fs = require('fs');
const yaml = require('js-yaml');
const PORT = 8000;
const HOST = "localhost";
const { spawn } = require('child_process');
var Process = require('./process.js')
let processes = [];

try {
    let config = yaml.safeLoad(fs.readFileSync('./config.yml', 'utf8'));

    var clients = [];

    // server
    var server = net.createServer()
    
    fd_out = fs.openSync('./logs/taskmaster.log', 'a');
    fd_err = fs.openSync('./logs/taskmaster.log', 'a');
    
    process.on('SIGHUP', () => {
        fs.writeSync(fd_out, `SIGHUP received. Stop and reboot\n`);
    });

    server.on('connection', function(socket) {
        let remoteAddress = socket.remoteAddress + ':' + socket.remotePort;
        // console.log(`serverconnected with ${remoteAddress}\n`);
        fs.writeSync(fd_out, `serverconnected with ${remoteAddress}\n`);
        clients.push(socket);
    
        socket.on('data', function(receivedData){
          fs.writeSync(fd_out, `cmd : ${receivedData}\n`);
        //server's response back to the TCP-CLIENT
        //   console.log('Server msg: ' + receivedData + ' received');
          socket.write('Server msg: ' + receivedData + ' received');
        })
    });
    
    server.on('error', function(error) {
        fs.writeSync(fd_out, `error : ${error}\n`);
    });
    
    server.on('exit', function() {
        fs.writeSync(fd_out, `exit\n`);
    });
    
    server.listen(PORT, HOST, function(err) {
        if (err)
        {
            process.exit(0);
            return ;
        }
        // config
        fs.writeSync(fd_out, `Process PID : ${process.pid}\n`);
        fs.writeSync(fd_out, `Process PPID : ${process.ppid}\n\n`);
        Object.keys(config).forEach((key) => {
            fs.writeSync(fd_out, `lunch key : ${key}\n`);
            fs.writeSync(fd_out, `lunch data : ${JSON.stringify(config[key])}\n`);

            console.log(`Launch : ${key}`);
            console.log(`Launch config : ${JSON.stringify(config[key])}`);

            // let out = fs.openSync(config[key]["stdout"], 'a');
            // let err = fs.openSync(config[key]["stderr"], 'a');
            let index = 1;
            while (index <= config[key]["numprocs"])
            {
                let name = config[key]["numprocs"] > 1 ? `${key}s_${index}` : key;
                let proc = new Process(name, config[key], "STARTING");
                processes.push(proc);
                if (proc.autostart === true)
                {
                    let child = spawn("ls", [], {
                        detached: true,
                        stdio: ['ignore', proc.out, proc.err],
                        env: proc.env,
                        cwd: proc.cwd,
                        killSignal: proc.killSignal
                      });
                      child.on('exit', function (code, signal) {

                        switch (proc.autorestart) {
                            case true:
                              console.log('Restart ' + name);
                              break;
                            case false:
                                break;
                            case "unexpected":
                                if (Array.isArray(proc.exitcodes) && proc.exitcodes.includes(code))
                                {

                                } 
                                else if (proc.exitcodes == code)
                                {

                                }
                                else     
                                    console.log(`Not OK :  ${code} is not part of ` + proc.exitcodes + ' -> reboot');
                              // expected output: "Mangoes and papayas are $2.79 a pound."
                              break;
                            default:
                                console.log(`exit name : ${name} wide code : ${code}`);
                                fs.writeSync(fd_out, `exit name : ${name} wide code : ${code}\n`);   
                          }
                      });
                      child.unref();
                }
                index++;
            }
        });
        // console.log(processes);
    });

} catch (e) {
    console.log(e);
} 