https://stackoverflow.com/questions/29490670/how-does-rust-provide-move-semantics



In C++, copying is an operation that can be arbitrarily complex, due to custom copy constructors.
Rust doesn't want custom semantics of simple assignment or argument passing, and so takes a different approach.

**First, an assignment or argument passing in Rust is always just a simple memory copy.**

```rust
let foo = bar; // copies the bytes of bar to the location of foo (might be elided)

function(foo); // copies the bytes of foo to the parameter location (might be elided)
```

But what if the object controls some resources? Let's say we are dealing with a **simple smart pointer, Box**.

```rust
let b1 = Box::new(42);
let b2 = b1;
```

At this point, if just the bytes are copied over, wouldn't the destructor (**drop** in Rust) be called
for each object, thus freeing the same pointer twice and causing undefined behavior?

The answer is that **Rust moves by default**. This means that it copies the bytes to the new location,
and the old object is then gone. It is a compile error to access b1 after the second line above.
**And the destructor is not called for it.** The value was moved to b2, and b1 might as well not exist anymore.

**Rust's moving and copying semantics are very different from C++**. I'm going to take a different
approach to explain them than the existing answer.

In some discussions about C++'s move semantics, Rust's way was called **"destructive move"**.
There have been proposals to add the "move destructor" or something similar to C++ so that it
can have the same semantics.
**But move semantics as they are implemented in C++ don't do this. The old object is left behind, and its destructor is still called**.
Therefore, you need a move constructor to deal with the custom logic required by the move operation. Moving is just a specialized constructor/assignment operator that is expected to behave in a certain way.
