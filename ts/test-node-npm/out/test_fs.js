"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var fs = require("fs");
function test_fs() {
    fs.open('C:/Dev/sandbox/ts/node1/myfile', 'w', function (err, fd) {
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
}
exports.test_fs = test_fs;
//# sourceMappingURL=test_fs.js.map