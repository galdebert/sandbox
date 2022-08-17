const std = @import("std");


test "test root" {
    // https://github.com/ziglang/zig/issues/8234
    // but I don't see how this help ...
    //std.testing.refAllDecls(@This());

    // Note _ = @import("./arrays"); does NOT work at file scope
    _ = @import("./arrays.zig");
    _ = @import("./code_examples/zigg_zagg.zig");
}


