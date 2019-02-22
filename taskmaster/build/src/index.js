"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var fs = require("fs");
var yaml = require("js-yaml");
var Proc_1 = require("./models/Proc");
try {
    var config_1 = yaml.safeLoad(fs.readFileSync('./config.yaml', 'utf8'));
    var configs = void 0;
    Object.keys(config_1).forEach(function (key) {
        var proc = new Proc_1.Proc(key, config_1[key]);
        proc.print();
    });
}
catch (e) {
    console.log(e);
}
