const std = @import("std");

fn memory_leak_detection() !void {
    var general_purpose_allocator = std.heap.GeneralPurposeAllocator(.{}){};
    defer std.debug.assert(!general_purpose_allocator.deinit());

    const gpa = general_purpose_allocator.allocator();

    const u32_ptr = try gpa.create(u32);
    _ = u32_ptr; // silences unused variable error

    // oops I forgot to free!
}

test "memory_leak_detection" {
    zigg_zagg();
}
