// https://stevedonovan.github.io/rust-gentle-intro/1-basics.html
#![allow(dead_code)]

//--------------------------------------------------------------------------------------------------
fn main1() {
    let mut sum = 0;
    for i in 0..5 {
        sum += i;
    }
    println!("sum is {}", sum);
    let _x = abs(-2);
}

fn abs(x: i32) -> i32 {
    if x > 0 {
        x
    } else {
        -x
    }
}

//--------------------------------------------------------------------------------------------------
fn by_copy(x: i32) -> i32 {
    x + 1
}

fn by_ref(x: &i32) -> i32 {
    *x + 1
}

fn by_mut_ref(x: &mut i32) {
    *x = 1;
}

fn main2() {
    let x1 = 10;
    let x2 = by_copy(x1);
    let x3 = by_ref(&x2);

    // when calling a function that tale a mut ref
    let mut x4: i32 = 15; // mut required here
    by_mut_ref(&mut x4); // mut required here as well

    println!("{} {} {} {}", x1, x2, x3, x4);
}

//--------------------------------------------------------------------------------------------------
fn main3() {
    let arr = [10, 20, 30, 40];
    let first = arr[0];
    println!("first {}", first);

    for i in 0..4 {
        println!("[{}] = {}", i, arr[i]);
    }
    println!("length {}", arr.len());
}

// &[i32] is a slice, it keeps tracks of it size
fn sum(slice: &[i32]) -> i32 {
    let mut res = 0;
    for i in 0..slice.len() {
        res += slice[i]
    }
    res
}

fn main4() {
    let arr = [10, 20, 30, 40];
    let res = sum(&arr); // &arr is a slice. In rust, & means "borrow", the owner is still arr.
    println!("sum {}", res);
}

fn main5() {
    let ints = [1, 2, 3];
    let floats = [1.1, 2.1, 3.1];
    let strings = ["hello", "world"];
    let ints_ints = [[1, 2], [10, 20]];
    // You cannot print out an array in the usual way with {} but you can do a debug print with {:?}
    println!("ints {:?}", ints);
    println!("floats {:?}", floats);
    println!("strings {:?}", strings);
    println!("ints_ints {:?}", ints_ints);
}

//--------------------------------------------------------------------------------------------------
fn slice1() {
    let ints = [1, 2, 3, 4, 5];
    let slice1 = &ints[0..2];
    let slice2 = &ints[1..]; // open range!

    println!("ints {:?}", ints);
    println!("slice1 {:?}", slice1);
    println!("slice2 {:?}", slice2);
}

// #[cfg(test)]
fn slice2() {
    let ints = [1, 2, 3, 4, 5];
    let slice = &ints;
    let first = slice.get(0); // get() does not panic if out of bound
    let last = slice.get(5); // get() does not panic if out of bound

    println!("first {:?}", first);
    println!("last {:?}", last);

    println!("first {} {}", first.is_some(), first.is_none());
    println!("last {} {}", last.is_some(), last.is_none());
    println!("first value {}", first.unwrap());
}

//--------------------------------------------------------------------------------------------------

fn main() {
    //main1();
    //main2();
    //main3();
    //main4();
    //main5();
    //slice1();
    slice2();
}
