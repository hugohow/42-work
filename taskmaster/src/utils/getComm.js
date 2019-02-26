module.exports = function getComm(proc)
{
    switch(proc.state)
    {
        case "STOPPED":
            return `Stopped `;
        case "STARTING":
            return `Starting`;
        case "RUNNING":
            return `Running with pid ${proc.pid}`;
        case "BACKOFF":
            return `Backoff with pid ${proc.pid}`;
        case "STOPPING":
            return `Stopping with pid ${proc.pid}`;
        case "EXITED":
            return `Exited with pid ${proc.pid}`;
        case "FATAL":
            return `Fatal with pid ${proc.pid}`;
        default:
            return `Unknown error with pid ${proc.pid}`;
    }
}