var net = require('net');
const readline = require('readline');

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
})