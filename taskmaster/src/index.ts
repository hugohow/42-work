// import http = require('http'); 
import os = require('os'); 
import fs = require('fs');
import * as config_file from '../config.json';


class Config {
    address: number; 
    port: number;

    constructor (address: number, port: number) { 
        this.address = address; 
        this.port = port; 
    } 
}


interface Proc {
    cmd: string,
    numprocs: number,
    umask: string,
    workingdir: string,
    autostart: boolean,
    autorestart: string,
    exitcodes: number,
    startretries: number,
    starttime: number,
    stopsignal: string,
    stoptime: number,
    stdout: string,
    stderr: string
}
  


class Process { 
    nodePort: number; 
  
    constructor (port: number) { 
        this.nodePort = port; 
    } 
  
    onRequest() { 
        console.log("resquest"); 
  
        fs.readFile('./index.html', (err: Error, data: Buffer) => { 
            if (err) { 
                return ;
                // throw err; 
            } 
        //     response.writeHead(200, {'Content-Type': 'text/html'}); 
        //     response.write(data); 
        //     response.end(); 
        }); 
    }
  
    onStart() { 
        console.log("début");
        this.onRequest();
        // let httpServer = http.createServer(this.onRequest); 
        // httpServer.listen(this.nodePort); 
        // console.log('Server listenning on http://' + os.hostname() + ':' + this.nodePort + '/'); 
    } 
} 
  
let daemon = new Process(8080).onStart();
let config_list:Config[] = [];
Object.keys(config_file).forEach(function(key){
    if (key)
    {

    }
    config_list.push(new Config(22, 222));
});
console.log(daemon);

console.log(config_list[0], config_list[1])
