# cargo

https://doc.rust-lang.org/cargo/getting-started/first-steps.html

- init `cargo init`
- build `cargo build` or `cargo build --release`
- run `cargo run` or ./target/debug/hello_world

Cargo does four things:
- Introduces two metadata files with various bits of package information.
- Fetches and builds your package’s dependencies.
- Invokes rustc or another build tool with the correct parameters to build your package.
- Introduces conventions to make working with Rust packages easier.

`cargo new hello_world --bin`
We’re passing --bin because we’re making a binary program: if we were making a library, we’d pass --lib. This also initializes a new git repository by default. If you don't want it to do that, pass `--vcs` none.


**crates.io** is the Rust community's central package registry that serves as a location to discover and download packages. cargo is configured to use it by default to find requested packages.


Package Layout

- Cargo.toml and Cargo.lock are stored in the root of your package (package root).
- Source code goes in the src directory.
- The **default library** file is `src/lib.rs`.
- The **default executable** file is `src/main.rs`.
  - **Other executables** can be placed in `src/bin/`.
- Benchmarks go in the benches directory.
- Examples go in the examples directory.
- Integration tests go in the tests directory.



# How to Debug Rust with Visual Studio Code

https://www.forrestthewoods.com/blog/how-to-debug-rust-with-visual-studio-code/

- Click Debug -> Add Configuration
- If you're on Windows then select `C++ (Windows)`
- If you're on Mac or Linux then select `LLDB: Custom Launch`

Next, you should verify breakpoints are enabled in settings.json

```json
"debug.allowBreakpointsEverywhere": true, // false by default
```

