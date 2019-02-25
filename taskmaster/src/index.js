const os = require('os'); 
const fs = require('fs');
var net = require('net');
const yaml = require('js-yaml');
const readline = require('readline');
const { spawn, fork } = require('child_process');





// var net = require('net');

// var server = net.createServer(function(socket) {
// 	socket.write('Echo server\r\n');
// 	socket.pipe(socket);
// });

// server.listen(1337, '127.0.0.1');

try {
    const config = yaml.safeLoad(fs.readFileSync('./config.yml', 'utf8'));
    let configs = [];

        const rl = readline.createInterface({
            input: process.stdin,
            output: process.stdout
        });
        // out = fs.openSync('./taskmaster.log', 'a');
        // err = fs.openSync('./taskmaster.log', 'a');
        // const daemon = fork('./src/daemon.js', [], {
        //     detached: true,
        //     // stdio: ['ignore', 1, 2, 'ipc']
        //     stdio: ['ignore', out, err, 'ipc']
        // });
        // daemon.unref();
        // daemon.on('exit', (code) => {
        //     console.log(`Daemon exited with code ${code}`);
        // });
        // daemon.on('message', function(msg) {
        //     console.log("message from daemon " + JSON.stringify(msg));
        //     if (msg.status === "ok")
        //     {
                var client = new net.Socket()

                var config_host = {
                    host: 'localhost',
                    port: 8000
                };
                client.connect({
                    host: config_host.host,
                    port: config_host.port
                }, function() {
                //     // client.write("Hello From Client " + client.address().address);


                    rl.setPrompt('$> ');
                    rl.prompt();
            
                    rl.on('line', function(line) {
                        switch(line.trim()) {
                            case 'exit':
                                console.log('exit');
                                process.exit(0);
                            default:
                                client.write(line.trim() + "\n");
                                process.stdout.write(line.trim() + "\n");
                            break;
                        }
                        rl.prompt();
                    })

                // client.on('error', function (err) {
                //     console.log('Error : ', err);
                // });
                
                // client.on('close', function () {
                //     console.log('socket closed');
                // });
        })


        

        // var access = fs.createWriteStream('taskmaster.log', {
        //     fd: 1
        // });


        // write(JSON.stringify(os.cpus()));
        // Object.keys(config).forEach((key) => {


        //     console.log(key);
        //     console.log(config[key]);

        //     let out;
        //     let err;
        //     if (config[key]["stdout"] && config[key]["stderr"])
        //     {
        //         out = fs.openSync(config[key]["stdout"], 'a');
        //         err = fs.openSync(config[key]["stderr"], 'a');
        //     }
        //     const child = spawn("env", [], {
        //       detached: true,
        //       stdio: ['ignore', out, err],
        //       env: process.env
        //     });
        //     child.on('exit', function (code, signal) {
        //         console.log(`child ${JSON.stringify(child)}`);
        //       });
        //     // child.unref();
        // })
    // console.log("server : ", server);
    
} catch (e) {
    console.log(e);
}