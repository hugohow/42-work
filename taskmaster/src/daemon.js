var net = require("net");
const fs = require('fs');
var clients = [];

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

server.listen(8000);