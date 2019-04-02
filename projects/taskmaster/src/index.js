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
    console.log('\x1b[41mError: Another program is already listening on a port that one of our HTTP servers is configured to use.  Shut this program down first before starting supervisord.\x1b[0m');
    rl.close();
});

client.on('close', function () {
});