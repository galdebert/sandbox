export function test_awful_parts_in_js() {
  // null and undefined
  // You will need to deal with both. Just check for either with == check.
  // Imagine you are doing `foo.bar == undefined` where bar can be one of:
  console.log(undefined == undefined); // true
  console.log(null == undefined); // true
  console.log(0 == undefined); // false
  console.log('' == undefined); // false
  console.log(false == undefined); // false
  // Recommend == null to check for both undefined or null
  // You generally don't want to make a distinction between the two


  // To check if a variable is defined or not at a global level you normally use typeof :
  if (typeof someglobal !== 'undefined') { // someglobal is now safe to use
    console.log(someglobal);
  }

  // Any access to this keyword within a function is actually controlled by how the function is actually called.
  // It is commonly referred to as the calling context.
  // Here is an example:
  function foo() {
    console.log(this);
  }
  foo(); // logs out the global e.g. `window` in browsers
  let bar = {
    foo
  }
  bar.foo(); // Logs out `bar` as `foo` was called on `bar`
  // So be mindful of your usage of this
  // If you want to disconnect this in a class from the calling context use an arrow function, more on that later.
}

