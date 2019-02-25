var net = require("net");
var clients = [];

var server = net.createServer()

server.on('connection', function(socket) {
    let remoteAddress = socket.remoteAddress + ':' + socket.remotePort;
    console.log("serverconnected with " + remoteAddress);
    clients.push(socket);

    socket.on('data', function(receivedData){
      console.log('data from ' + remoteAddress);
      console.log('data ' + receivedData);

      //server's response back to the TCP-CLIENT
      socket.write('Server msg: ' + receivedData + ' received');
    })
});

server.listen(8000);