function log(s) {
  console.log(s);
}

function func_returning_promise(myfunc_arg) {
  log('in func_returning_promise function');
  return new Promise(function (resolve, reject) { // function (res, rej) is also commonly used
    log('in promise function');
    if (myfunc_arg) {
      var resolve_arg = { result: 1 };
      log('call resolve(resolve_arg);');
      resolve(resolve_arg);
    } else {
      var reject_arg = 'error';
      log('call reject(reject_arg);');
      reject(reject_arg);
    }
  });
}

function func_toplevel(myfunc_arg) {
  log(`func_toplevel(${myfunc_arg})`);
  var chained_promise = func_returning_promise(myfunc_arg).then(function (resolve_arg) {
    log(`in resolve continuation, result = ${resolve_arg.result}`);
  }).catch(function (reject_arg) {
    log(`in reject continuation, error = ${reject_arg}`);
  });
}

func_toplevel(true);
func_toplevel(false);



// OK
function b(result_a) {
  return LoadFile(result_a);
}

// KO
function b(result_a) {
  LoadFile(result_a); // the LoadFile promise will be executed but no other promise will depend on it
}

// OK
function c(result_a) {
  log("debug");
}


Promise.resolve()
.then(() => a())
.then(result_a => {
  return Promise.resolve()
    .then(() => b(result_a)) // function() { return b(result_a); } 
    .then(() => c(result_a)) // 
    .then(() => d(result_a))
}).then(() => log('done'))

