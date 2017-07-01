import * as fs from "fs";

fs.open('myfile', 'wx', (err, fd) => {
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
