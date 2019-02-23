const os = require('os'); 
const fs = require('fs');

const yaml = require('js-yaml');

const { spawn } = require('child_process');

try {
    const config = yaml.safeLoad(fs.readFileSync('./config.yml', 'utf8'));
    let configs = [];
    Object.keys(config).forEach((key) => {


        console.log(key);
        console.log(config[key]);

        let out;
        let err;
        if (config[key]["stdout"] && config[key]["stderr"])
        {
            out = fs.openSync(config[key]["stdout"], 'a');
            err = fs.openSync(config[key]["stderr"], 'a');
        }
        const child = spawn("env", [], {
          detached: true,
          stdio: ['ignore', out, err],
          env: process.env
        });
        child.on('exit', function (code, signal) {
            console.log(`child ${JSON.stringify(child)}`);
          });
        // child.unref();
    })
} catch (e) {
    console.log(e);
}