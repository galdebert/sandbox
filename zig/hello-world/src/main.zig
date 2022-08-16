const std = @import("std");

pub fn main() !void {
    const stdout = std.io.getStdOut().writer();
    try stdout.print("{s}, {s}!\n", .{"Hello", "world"});

    std.log.info("All your codebase are belong to us.", .{});

    std.debug.print("All your codebase are belong to us.", .{});
}

// pub fn main() anyerror!void {
//     std.log.info("All your codebase are belong to us.", .{});
// }


test "basic test" {
    try std.testing.expectEqual(10, 3 + 7);
}
