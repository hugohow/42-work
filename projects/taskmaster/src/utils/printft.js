Object.filter = function( obj, keyTable) {
    var result = {};
    var key;

    for (key in obj) {
        if (obj.hasOwnProperty(key) && keyTable(key)) {
            result[key] = obj[key];
        }
    }

    return result;
};


module.exports = {
    reduceTable: function reduceTable(processes) {
        let processes_print = processes.map(function(proc) {
            return Object.filter(proc, function(key) {
                if (key === "name")
                    return true;
                if (key === "state")
                    return true;
                if (key === "comment")
                    return true;
                return false;
                // return true;
            })
        })
        return processes_print;
    },
    printProcesses: function printProcesses(processes) {
        console.table(this.reduceTable(processes));
    }
}
