#![allow(unused_variables)]

fn strings1() {
    let s1 = "hello".to_string();
    let s2 = s1.clone();
    assert!(s1 == s2); // cool
    assert!(s1 == "hello"); // fine
    //assert!(s1 == &s2); // compile error can't compare `String` with `&String`

    // You cannot concatenate two String values, but you can concatenate a String with a &str
    //let s3 = s1 + s2; // compile error
    let s3 = s1 + &s2;
    println!("{}", s3)
}

const MY_CONST: &str = "myconst";

fn strings2() {
  let s1 = "hello".to_string();
  let s2 = &s1;
  let s3 = &s1;
  let s4 = "bye";
  
  //let tup = (s1, s2, s3);
  //println!("{:?}", tup);
  //println!("{:?} {:?} {:?} {:?}", s1, s2, s3, s4);
}


//   let mut1 = s1.as_mut();

fn strings3() {
  let s1 = "hello".to_string();
  let s2 = s1; // value moved here
  let s3 = &s1; // move after use
}

fn main() {
  strings1();
  strings2();
}
