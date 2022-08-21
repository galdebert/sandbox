// cargo run --bin func-return-multiple-values

fn ret_void() {
    return;
}

fn ret_void_2() -> () {
    return ();
}

fn ret_1() -> i32 {
    return 1;
}

fn my_func() -> (i32, i32) {
    return (1, 2);
}

fn main() {
    ret_void();
    ret_void_2();

    let z = ret_1();
    println!("{z}");

    let (x, y) = my_func();
    println!("{x} {y}");
}
