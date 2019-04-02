

module.exports = function stopProcesses(processes, data)
{
    console.log("Stop processes");
    console.log(data);
    console.log(processes);
    // stop <name>
    // stop <gname>:*
    // stop <name> <name>
    // stop all
    if (data.length === 1)
    {
        return {
            type: "stop",
            receivedData: data,
            status: 0,
            payload: {
                message: "Il manque un argument"
            }
        }
    }
    if (data[1] === "all")
    {
        var length = processes.length;
        var i = 0;
        processes.forEach(function(process){
            process.stop();
            if (process.spawn)
            {
                process.spawn.on('exit', function() {
                    i++;
                    if (i === length)
                        return {
                            type: "stop",
                            receivedData: data,
                            status: 1,
                            payload: {}
                        }  
                })
            }
            else
                i++;
            if (i === length)
                return {
                    type: "stop",
                    receivedData: data,
                    status: 1,
                    payload: {}
                }  
        });      
    }
    else
    {
        return {
            type: "stop",
            receivedData: data,
            status: 1,
            payload: {}
        }
    }
}