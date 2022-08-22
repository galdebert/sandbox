// cargo run --bin func-return-multiple-values

fn ret_void_1() {}

fn ret_void_2() {
    return;
}

fn ret_void_3() -> () {
    return ();
}

fn ret_1() -> i32 {
    return 1;
}

// return multiple values using tuple
fn ret_2_tuple() -> (i32, i32) {
    return (1, 2);
}

struct Pair {
    a: i32,
    b: i32,
}

// return multiple values using struct
fn ret_2_struct() -> Pair {
    Pair { a: 1, b: 2 }
}

// return multiple values using array
fn ret_2_array() -> [i32; 2] {
    return [1, 2];
}

fn main() {
    ret_void_1();
    ret_void_2();
    ret_void_3();

    let z = ret_1();
    println!("{z}");

    {
        // destructure of a tuple
        let (a, b) = ret_2_tuple();
        println!("{a} {b}");
    }

    {
        // destructure of a struct (note how Pair is necessary here)
        // destructure syntax is designed to be symmetric with constructor syntax
        let Pair { a, b } = ret_2_struct();
        println!("{a} {b}");
    }

    {
        // destructure of an array
        let [a, b] = ret_2_array();
        println!("{a} {b}");
    }
}
