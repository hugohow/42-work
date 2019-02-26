var net = require("net");
const fs = require('fs');
const yaml = require('js-yaml');
const PORT = 8000;
const HOST = "localhost";
var Process = require('./process.js')
let processes = [];
var printProcesses = require("./utils/printProcesses");

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

            let index = 1;
            while (index <= config[key]["numprocs"])
            {
                let name = config[key]["numprocs"] > 1 ? `${key}s_${index}` : key;
                let proc = new Process(name, config[key]);
                processes.push(proc);
                if (proc.autostart === true)
                {
                    proc.start();
                }
                index++;
            }
        });
        // printProcesses(processes);
    });

} catch (e) {
    console.log(e);
} 