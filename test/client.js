var net = require('net');


var config = {
    host: 'localhost',
    port: 8000
};

var move = {
    forward: 'READER_FWD',
    backward: 'READER_BWD'
};

var client = new net.Socket();

client.connect({
        host: config.host,
        port: config.port
    }, function () {
        console.log('connected to ' + config.host + ':' + config.port);
        client.write(move.forward, function () {
            console.log('move forward command sent');
        });
});

client.on('data', function (data)
 {
    var str = data.toString();
    console.log("Client: message reçu" + str);
    // if (str === 'ACK') 
    // {

    //     setTimeout(function() 
    //     {   
    //         console.log('ACK received');
    //         client.write(move.backward, function () 
    //         {
    //             console.log('move backward sent');
                client.end();

    //         }); 
    //     }, 3000);

    // }

});

client.on('error', function (err) {
    console.log('Error : ', err);
});

client.on('close', function () {
    console.log('socket closed');
});