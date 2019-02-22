"use strict";
var __importStar = (this && this.__importStar) || function (mod) {
    if (mod && mod.__esModule) return mod;
    var result = {};
    if (mod != null) for (var k in mod) if (Object.hasOwnProperty.call(mod, k)) result[k] = mod[k];
    result["default"] = mod;
    return result;
};
Object.defineProperty(exports, "__esModule", { value: true });
var fs = require("fs");
var config_file = __importStar(require("../config.json"));
var Config = /** @class */ (function () {
    function Config(address, port) {
        this.address = address;
        this.port = port;
    }
    return Config;
}());
var Process = /** @class */ (function () {
    function Process(port) {
        this.nodePort = port;
    }
    Process.prototype.onRequest = function () {
        console.log("resquest");
        fs.readFile('./index.html', function (err, data) {
            if (err) {
                return;
                // throw err; 
            }
            //     response.writeHead(200, {'Content-Type': 'text/html'}); 
            //     response.write(data); 
            //     response.end(); 
        });
    };
    Process.prototype.onStart = function () {
        console.log("début");
        this.onRequest();
        // let httpServer = http.createServer(this.onRequest); 
        // httpServer.listen(this.nodePort); 
        // console.log('Server listenning on http://' + os.hostname() + ':' + this.nodePort + '/'); 
    };
    return Process;
}());
var daemon = new Process(8080).onStart();
var config_list = [];
Object.keys(config_file).forEach(function (key) {
    if (key) {
    }
    config_list.push(new Config(22, 222));
});
console.log(daemon);
console.log(config_list[0], config_list[1]);
