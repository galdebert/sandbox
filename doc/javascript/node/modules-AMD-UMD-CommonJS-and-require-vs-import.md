# What Is AMD, CommonJS, and UMD?

https://www.davidbcalhoun.com/2014/what-is-amd-commonjs-and-umd/

# AMD

Asynchronous Module Definition (AMD) has **gained traction on the frontend**, with RequireJS being the most popular implementation.

module `foo` with a single dependency on jquery
```js
// filename: foo.js
define(['jquery'], function ($) { // jquery as dependencies
    function myFunc(){}; // methods
    return myFunc; // exposed public methods
});
```

# CommonJS

**CommonJS** is a style you may be familiar with if you’re written anything in **Node** (which uses a slight variant).

It’s also been gaining traction on the **frontend** with **Browserify**.

module `foo` with a single dependency on jquery
```js
var $ = require('jquery'); // jquery as dependencies
function myFunc(){}; // methods
module.exports = myFunc; // exposed public method (single)
```

exporting multiple functions
```js
var $ = require('jquery'); // jquery as dependencies
function myFunc1(){}; // methods
function myFunc2(){}; // methods
module.exports.myFunc1 = myFunc1;
module.exports.myFunc2 = myFunc2;
```

exporting multiple functions - alternative 
```js
var $ = require('jquery'); // jquery as dependencies
function myFunc1(){}; // methods
function myFunc2(){}; // methods
exports.myFunc1 = myFunc1;
exports.myFunc2 = myFunc2;
```

# UMD

Since CommonJS and AMD styles have both been equally popular, it seems there’s yet no consensus. This has brought about the push for a **universal pattern that supports both styles**, which brings us to none other than the Universal Module Definition.

The pattern is admittedly ugly, but is both AMD and CommonJS compatible, as well as supporting the old-style “global” variable definition:

```js
(function (root, factory) {
    if (typeof define === 'function' && define.amd) {
        define(['jquery'], factory); // AMD
    } else if (typeof exports === 'object') {
        module.exports = factory(require('jquery')); // Node, CommonJS-like
    } else {
        root.returnExports = factory(root.jQuery); // Browser globals (root is window)
    }
}(this, function ($) {
    function myFunc(){}; // methods
    return myFunc; // exposed public method
}));
```

# Using Node.js require vs. ES6 import/export

https://stackoverflow.com/questions/31354559/using-node-js-require-vs-es6-import-export

2 choices:
- Importing modules using **Node require**, and exporting using module.exports and exports.foo.
- Importing modules using **ES6 import**, and exporting using ES6 export

Keep in mind that there is no JavaScript engine yet that natively supports **ES6 modules**.

**Transpilers (Babel, Typescript, webpack) transform import and export declaration into CommonJS (require/module.exports).**

So even if you use ES6 module syntax, you will be using CommonJS under the hood if you run the code in Node.

## Require

- You can have dynamic loading where the **loaded module name isn't predefined** /static, or where you conditionally load a module only if it's "truly required" (depending on certain code flow).
- Loading is **synchronous**. That means if you have multiple requires, they are loaded and processed one by one.

## ES6 Imports

- You can **use named imports to selectively load only the pieces you need**. That can save memory.
- Import **can** be asynchronous (and in current ES6 Module Loader, it in fact is) and can perform a little better.

While **ES6 provides the import and export syntax, it does not define how modules should be loaded**. The important part is that the **declarations are statically analyzable, so that dependencies can be determined without executing the code**. This would allow a module loader to either load a module synchronously or asynchronously. But ES6 modules by themselves are not synchronous or asynchronous.

**If you develop for node, then you are likely compiling ES6 modules to require anyway**, so you are using Node's module system and loader anyway.

In browsers the ES6 import/export is not implmented yet, a transpiler is still required.

Using ES6 modules can be useful for **tree shaking**; i.e. enabling **Webpack 2**, Rollup (or other **bundlers**) **to identify code paths that are not used/imported, and therefore don't make it into the resulting bundle**.
