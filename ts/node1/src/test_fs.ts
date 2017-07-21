import * as fs from "fs";

export function test_fs() {
    fs.open('C:/Dev/sandbox/ts/node1/myfile', 'w', (err, fd) => {
        if (err) {
            console.error('error in fs.open()');
            throw err;
        }
        console.log('fs.open() done');

        fs.write(fd, 'Hello Node.js', (err, written, string) => {
            if (err) {
                console.error('error in fs.write()');
                throw err;
            }
            console.log('fs.write() done');
        });
    });
}
