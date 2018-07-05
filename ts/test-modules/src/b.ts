console.log('this is a message from the module b loading');

function g() { console.log('b'); }

export function f() { g(); }