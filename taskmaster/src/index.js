var net = require('net');
const readline = require('readline');
var printft = require("./utils/printft");

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

var client = new net.Socket()

var config_host = {
    host: 'localhost',
    port: 8000
};


client.connect({
    host: config_host.host,
    port: config_host.port
}, function() {
    rl.prompt();
    rl.on('line', function(line) {
        switch(line.trim()) {
            case 'exit':
                process.exit(0);
            default:
                client.write(line.trim() + "\n");
            break;
        }
    })
})

client.on('data', function (data)
 {
     if (typeof (data.toString('utf8')) === "string")
        console.log(data.toString('utf8'));
    else
        printft.printProcesses(JSON.parse(data.toString()));
});

client.on('error', function (err) {
    console.log('Error : ', err);
    rl.close();
});

client.on('close', function () {
    console.log('socket closed');
});