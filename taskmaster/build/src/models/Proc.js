"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var Proc = /** @class */ (function () {
    function Proc(key, json) {
        this.key = key;
        this.json = json;
    }
    Proc.prototype.print = function () {
        console.log(this);
    };
    return Proc;
}());
exports.Proc = Proc;
