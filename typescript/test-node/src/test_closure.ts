
export function test_closure() {
  console.log('\n---- test_closure');

  function outerFunction(arg: any) {
    var variableInOuterFunction = arg;
    return function () {
      console.log(variableInOuterFunction);
    }
  }
  var innerFunction = outerFunction("hello closure!");
  // Note the outerFunction has returned
  innerFunction(); // logs hello closure
}