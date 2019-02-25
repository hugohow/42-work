var net = require("net");
const fs = require('fs');
const yaml = require('js-yaml');

try {
    const config = yaml.safeLoad(fs.readFileSync('./config.yml', 'utf8'));

    var clients = [];

    // server
    var server = net.createServer()
    
    fd_out = fs.openSync('./taskmaster.log', 'a');
    fd_err = fs.openSync('./taskmaster.log', 'a');
    
    
    server.on('connection', function(socket) {
        let remoteAddress = socket.remoteAddress + ':' + socket.remotePort;
        // console.log(`serverconnected with ${remoteAddress}\n`);
        fs.writeSync(fd_out, `serverconnected with ${remoteAddress}\n`);
        clients.push(socket);
    
        socket.on('data', function(receivedData){
          fs.writeSync(fd_out, `data : ${receivedData}\n`);
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
    
    server.listen(8000, function(err) {
        if (err)
        {

            return ;
        }
        // config

        Object.keys(config).forEach((key) => {
            fs.writeSync(fd_out, `lunch key : ${key}\n`);
            fs.writeSync(fd_out, `lunch key : ${JSON.stringify(config[key])}\n`);

            // const child = spawn("env", [], {
            //   detached: true,
            //   stdio: ['ignore', out, err],
            //   env: process.env
            // });
            // child.on('exit', function (code, signal) {
            //     console.log(`child ${JSON.stringify(child)}`);
            //   });
            // child.unref();
        });
    });


} catch (e) {
    console.log(e);
} 