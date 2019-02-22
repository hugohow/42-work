import os = require('os'); 
import fs = require('fs');

import yaml = require('js-yaml');
import { Proc } from './models/Proc';


try {
    const config = yaml.safeLoad(fs.readFileSync('./config.yaml', 'utf8'));
    let configs: string[];
    Object.keys(config).forEach((key) => {
        var proc = new Proc(key, config[key]);
        proc.print();
    })
} catch (e) {
    console.log(e);
}