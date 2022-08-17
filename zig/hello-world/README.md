# README

`zig build run` builds and runs `main.zig`

`zig test src/arrays.zig` builds and runs `src/arrays.zig` but also creates an unwanted `src/zig-cache`

so I use `zig test --cache-dir zig-cache src/structs.zig`

# How o run all tests

https://github.com/ziglang/zig/issues/8234

```ts
test {
    _ = @import("src/test_file_1.zig");
    // ...
    _ = @import("src/test_file_N.zig");
}
```

or

you can do `std.testing.refAllDecls(@This());` to reference all constants (basically all imported files).


# learn resources

https://ziglang.org/learn

Zig Newcomer Programming FAQs https://github.com/ziglang/zig/wiki/Zig-Newcomer-Programming-FAQs

FAQ https://github.com/ziglang/zig/wiki/FAQ
