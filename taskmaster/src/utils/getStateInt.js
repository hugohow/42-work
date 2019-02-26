module.exports = function getStateInt(state)
{
    switch(state)
    {
        case "STOPPED":
            return 0;
        case "STARTING":
            return 10;
        case "RUNNING":
            return 20;
        case "BACKOFF":
            return 30;
        case "STOPPING":
            return 40;
        case "EXITED":
            return 100;
        case "FATAL":
            return 200;
        default:
            return 1000;
    }
}