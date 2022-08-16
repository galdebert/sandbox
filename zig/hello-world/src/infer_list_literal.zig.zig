const std = @import("std");
const expect = std.testing.expect;

test "fully anonymous list literal" {
    try dump(.{ @as(u32, 1234), @as(f64, 12.34), true, "hi"});
}

fn dump(args: anytype) !void {
    try expect(args.@"0" == 1234);
    try expect(args.@"1" == 12.34);
    try expect(args.@"2");
    try expect(args.@"3"[0] == 'h');
    try expect(args.@"3"[1] == 'i');
}