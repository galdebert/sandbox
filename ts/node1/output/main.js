"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var fs = require("fs");
fs.open('myfile', 'wx', function (err, fd) {
    if (err) {
        console.error('error in fs.open()');
        throw err;
    }
    console.log('fs.open() done');
    fs.write(fd, 'Hello Node.js', function (err, written, string) {
        if (err) {
            console.error('error in fs.write()');
            throw err;
        }
        console.log('fs.write() done');
    });
});
