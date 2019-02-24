var net = require('net');

console.log(`The daemon process is pid ${process.pid}`);
console.log(`The parent process is pid ${process.ppid}`);
var server = net.createServer();
server.listen(1337,  '127.0.0.1', () => {
    console.log('TCP Server is running on port ' + 1337 +'.');
});
let sockets = [];

server.on('connection', function(sock) {
    console.log('CONNECTED: ' + sock.remoteAddress + ':' + sock.remotePort);
    // sockets.push(sock);

    // sock.on('data', function(data) {
    //     console.log('DATA ' + sock.remoteAddress + ': ' + data);
    //     // Write the data back to all the connected, the client will receive it as data from the server
    //     sockets.forEach(function(sock, index, array) {
    //         sock.write(sock.remoteAddress + ':' + sock.remotePort + " said " + data + '\n');
    //     });
    // });
});
// process.on('message', (msg) => {
//     console.log('Message from parent:' + JSON.stringify(msg));
// });
// setTimeout(() => {  
//     process.exit(0);
// }, 100000);