module.exports = function isExitCodesValid(exitcodes, code)
{
    if (Array.isArray(exitcodes) && exitcodes.includes(code))
        return true;
    else if (this.exitcodes == code)
        return true;
    return false;
}
