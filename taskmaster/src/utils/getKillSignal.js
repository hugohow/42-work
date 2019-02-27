module.exports = function getKillSignal(stopsignal)
{
    if (stopsignal)
    {
        console.log(stopsignal.substring(0,3));
        if (stopsignal.substring(0,3) === "SIG")
        {
            // if (["SIGTERM", "SIGINT", "SIGQUIT", "SIGHUP", "SIGUSR2"].includes(stopsignal))
                return stopsignal;
            // return "SIGTERM";
        }
        else
        {
            // if (["TERM", "INT", "QUIT", "HUP", "USR2"].includes(stopsignal))
                return "SIG" + stopsignal;
            // return "SIGTERM";
        }
    }
    return 'SIGTERM';
}