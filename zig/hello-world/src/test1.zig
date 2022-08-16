pub fn test1() void {

}

test "basic test1" {
    try std.testing.expectEqual(10, 3 + 7);
}
