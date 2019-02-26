var net = require("net");
const fs = require('fs');
const yaml = require('js-yaml');
const PORT = 8000;
const HOST = "localhost";
var Process = require('./process.js')
let processes = [];
var printft = require("./utils/printft");

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
          if (receivedData.toString('utf8'))
          {
            let data = receivedData.toString('utf8').replace("\n", "").split(" ");
            if (data[0] === "add")
                socket.write(Buffer.from("add"));
            else if (data[0] === "remove")
                socket.write(Buffer.from("remove"));
            else if (data[0] === "update")
                socket.write(Buffer.from("update"));
            else if (data[0] === "clear")
                socket.write(Buffer.from("clear"));
            else if (data[0] === "reload")
                socket.write(Buffer.from("reload"));
            else if (data[0] === "restart")
                socket.write(Buffer.from("restart"));
            else if (data[0] === "start")
                socket.write(Buffer.from("start"));
            else if (data[0] === "status")
                socket.write(Buffer.from(JSON.stringify(printft.reduceTable(processes))));
            else if (data[0] === "stop")
                socket.write(Buffer.from("start"));
            else
                socket.write(Buffer.from("unknown"));
          }
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
                index++;
            }
        });
    });

} catch (e) {
    console.log(e);
} 