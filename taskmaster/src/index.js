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

client.on('data', function (dataReceived)
{
    let data = JSON.parse(dataReceived.toString('utf8'))
    if (data.type === "status")
    {
        console.table(data.payload);
    }
    else
    {
        console.log(data);
    }

});

client.on('error', function (err) {
    console.log('Error : ', err);
    rl.close();
});

client.on('close', function () {
    console.log('socket closed');
});