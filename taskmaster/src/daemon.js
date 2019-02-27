var net = require("net");
const fs = require('fs');
const yaml = require('js-yaml');
const PORT = 8000;
const HOST = "localhost";
var Process = require('./process.js')
let processes = [];
var printft = require("./utils/printft");
var stopProcesses = require("./utils/stopProcesses")




fd_out = fs.openSync('./logs/taskmaster.log', 'a');
fd_err = fs.openSync('./logs/taskmaster.log', 'a');


function startAllProcesses(config)
{
    let list = [];

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
            list.push(proc);
            index++;
        }
    });
    return (list);
}

try {
    let config = yaml.safeLoad(fs.readFileSync('./config.yml', 'utf8'));

    var clients = [];

    // server
    var server = net.createServer()
    
    process.on('SIGHUP', () => {
        fs.writeSync(fd_out, `SIGHUP received. Stop and reboot\n`);
    });

    process.on('SIGCHLD', () => {
        // console.log('a child is stopped')
    })

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

            if (data[0] === "update")
            {
                socket.write(Buffer.from(JSON.stringify({
                    type: "update",
                    receivedData: data,
                    status: 1,
                    payload: {}
                })));
            }
            else if (data[0] === "shutdown")
            {
                stopProcesses(processes, ["shutdown", "all"]);
                socket.write(Buffer.from(JSON.stringify({
                    type: "shutdown",
                    receivedData: data,
                    status: 1,
                    payload: {}
                })));
                process.exit(0);
            }
            else if (data[0] === "reload")
            {
                socket.write(Buffer.from(JSON.stringify({
                    type: "reload",
                    receivedData: data,
                    status: 1,
                    payload: {}
                })));
            }
            else if (data[0] === "restart")
            {
                socket.write(Buffer.from(JSON.stringify({
                    type: "restart",
                    receivedData: data,
                    status: 1,
                    payload: {}
                })));
            }
            else if (data[0] === "start")
            {
                socket.write(Buffer.from(JSON.stringify({
                    type: "start",
                    receivedData: data,
                    status: 1,
                    payload: {}
                })));
            }
            else if (data[0] === "status")
            {
                socket.write(Buffer.from(JSON.stringify({
                    type: "status",
                    receivedData: data,
                    status: 1,
                    payload: printft.reduceTable(processes)
                })));
            }
            else if (data[0] === "stop")
            {
                stopProcesses(processes, data);
                socket.write(Buffer.from(JSON.stringify({
                    type: "stop",
                    receivedData: data,
                    status: 1,
                    payload: {}
                })));
            }
            else
            {
                socket.write(Buffer.from(JSON.stringify({
                    type: "unknown",
                    receivedData: data,
                    status: 1,
                    payload: {}
                })));
            }
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

        fs.writeFileSync("deamon.pid", `${process.pid}`);

        processes = startAllProcesses(config);

    });

} catch (e) {
    console.log(e);
} 