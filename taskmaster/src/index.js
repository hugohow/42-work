const os = require('os'); 
const fs = require('fs');

const yaml = require('js-yaml');
const readline = require('readline');
const { spawn } = require('child_process');

function executeLine(line, process)
{
    switch(line.trim()) {
        case 'exit':
            console.log('exit');
            process.exit(0);
        default:
            process.stdout.write(line.trim() + "\n");
        break;
    }
}

try {
    const config = yaml.safeLoad(fs.readFileSync('./config.yml', 'utf8'));
    let configs = [];

    const rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout
      });

    rl.setPrompt('$> ');
    rl.prompt();

    rl.on('line', function(line) {
        executeLine(line, process);
        rl.prompt();
    })
    

    // var access = fs.createWriteStream('taskmaster.log', {
    //     fd: 1
    // });


    // write(JSON.stringify(os.cpus()));
    // Object.keys(config).forEach((key) => {


    //     console.log(key);
    //     console.log(config[key]);

    //     let out;
    //     let err;
    //     if (config[key]["stdout"] && config[key]["stderr"])
    //     {
    //         out = fs.openSync(config[key]["stdout"], 'a');
    //         err = fs.openSync(config[key]["stderr"], 'a');
    //     }
    //     const child = spawn("env", [], {
    //       detached: true,
    //       stdio: ['ignore', out, err],
    //       env: process.env
    //     });
    //     child.on('exit', function (code, signal) {
    //         console.log(`child ${JSON.stringify(child)}`);
    //       });
    //     // child.unref();
    // })
} catch (e) {
    console.log(e);
}