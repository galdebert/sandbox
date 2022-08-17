const std = @import("std");

pub fn build(builder: *std.build.Builder) void {
    // Standard target options allows the person running `zig build` to choose
    // what target to build for. Here we do not override the defaults, which
    // means any target is allowed, and the default is native. Other options
    // for restricting supported target set are available.
    const target = builder.standardTargetOptions(.{});

    // Standard release options allow the person running `zig build` to select
    // between Debug, ReleaseSafe, ReleaseFast, and ReleaseSmall.
    const mode = builder.standardReleaseOptions();

    const exe = builder.addExecutable("hello-world", "src/main.zig");
    exe.setTarget(target);
    exe.setBuildMode(mode);
    exe.install();

    const run_cmd = exe.run();
    run_cmd.step.dependOn(builder.getInstallStep());
    if (builder.args) |args| {
        run_cmd.addArgs(args);
    }

    const run_step = builder.step("run", "Run the app");
    run_step.dependOn(&run_cmd.step);

    // zig build test
    const exe_tests = builder.addTest("src/main.zig");
    exe_tests.setTarget(target);
    exe_tests.setBuildMode(mode);

    const test_step = builder.step("test", "Run unit tests");
    test_step.dependOn(&exe_tests.step);

    // zig build test2
    const exe_tests2 = builder.addTest("src/test_root.zig");
    exe_tests2.setTarget(target);
    exe_tests2.setBuildMode(mode);

    const test_step2 = builder.step("test2", "Run unit tests2");
    test_step2.dependOn(&exe_tests2.step);

}
