module.exports = function stopProcesses(processes, data)
{
    // console.log("Stop processes");
    // console.log(data);
    // console.log(processes);
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
        processes.forEach(function(process){
            process.stop();
        });
        return {
            type: "stop",
            receivedData: data,
            status: 1,
            payload: {
                message: "Stop all"
            }
        }
    }
    return {
        type: "stop",
        receivedData: data,
        status: 1,
        payload: {}
    }
}