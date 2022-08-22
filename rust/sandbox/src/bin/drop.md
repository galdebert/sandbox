https://doc.rust-lang.org/rust-by-example/trait/drop.html

The Drop trait only has one method: drop, which is called automatically when an object goes out of scope.
The main use of the Drop trait is to free the resources that the implementor instance owns.

`Box`, `Vec`, `String`, `File`, and `Process` are some examples of types that implement the Drop trait to free resources.
The Drop trait can also be manually implemented for any custom data type.




