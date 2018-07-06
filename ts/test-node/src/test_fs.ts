import * as fs from 'fs';
import * as path from 'path';
import * as process from 'process';

// current working dir process.cwd
// __filename and __dirname are module-level variables.

export function test_path() {
  console.log('\n---- test_path');

  console.log(`process.cwd = ${process.cwd()}`);
  console.log(`__filename is the module path = ${__filename}`);
  console.log(`__dirname is the module containing dir = ${__dirname}`);
}

export function test_fs() {
  // 1
  console.log('\n---- test_path');
  let p = path.normalize(path.join(process.cwd(), 'data/myfile.txt'))
  console.log(`fs.open('${p}', 'w')`);
  fs.open(p, 'w', (err: any, fd: any) => {
    // 2
    if (err) {
      console.error('error in fs.open()');
      throw err;
    }
    console.log('fs.open() done');
    console.log(`fs.write(fd, 'Hello Node.js')`);
    fs.write(fd, 'Hello Node.js', (err: any, written: any, string: any) => {
      // 3
      if (err) {
        console.error('error in fs.write()');
        throw err;
      }
      console.log('fs.write() done');
    });
  });
}
