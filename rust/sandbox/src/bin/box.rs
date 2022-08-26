use std::mem;

/* https://doc.rust-lang.org/rust-by-example/std/box.html

All values in Rust are stack allocated by default. Values can be boxed (allocated on the heap) by
creating a Box<T>. A box is a smart pointer to a heap allocated value of type T. When a box goes out
of scope, its destructor is called, the inner object is destroyed, and the memory on the heap is freed.
*/

struct Point2d {
    x: f64,
    y: f64,
}

struct BoxCtnr {
    a: Box<Point2d>,
    b: Box<Point2d>,
}

fn main() {
    let point = Point2d { x: 1.0, y: 2.0 };
    let boxed_point: Box<Point2d> = Box::new(Point2d { x: 1.0, y: 2.0 });
    println!("{} {}", (*boxed_point).x, (*boxed_point).y);
    println!("{} {}", boxed_point.x, boxed_point.y); // NOTE the automatic

    let boxed_point2 = boxed_point; // move through a box
    println!("{} {}", boxed_point2.x, boxed_point2.y);

    let boxed_boxed_point: Box<Box<Point2d>> = Box::new(Box::new(Point2d { x: 1.0, y: 2.0 }));
    println!("{} {}", boxed_boxed_point.x, boxed_boxed_point.y); // equivalent

    println!("size_of_val(&point) = {}", mem::size_of_val(&point));
    println!(
        "size_of_val(&boxed_point) = {}",
        mem::size_of_val(&boxed_point2) // 8
    );
    println!(
        "size_of_val(&boxed_boxed_point) = {}",
        mem::size_of_val(&boxed_boxed_point) // 8
    );

    //------------------------------------------

    let box_ctnr = BoxCtnr {
        a: Box::new(Point2d { x: 1.0, y: 2.0 }),
        b: Box::new(Point2d { x: 1.0, y: 2.0 }),
    };
    // rust immutability is DEEP; everything reachable from a immutable reference is immutable
    // box_ctnr.a.x = 3.0;
    println!("{} {}", box_ctnr.a.x, box_ctnr.a.y);
    println!("{} {}", box_ctnr.b.x, box_ctnr.b.y);

    //------------------------------------------

    let mut mut_box_ctnr = BoxCtnr {
        a: Box::new(Point2d { x: 1.0, y: 2.0 }),
        b: Box::new(Point2d { x: 1.0, y: 2.0 }),
    };
    mut_box_ctnr.a.x = 3.0;
    mut_box_ctnr.a.y = 3.0;
    println!("{} {}", mut_box_ctnr.a.x, mut_box_ctnr.a.y);
    println!("{} {}", mut_box_ctnr.b.x, mut_box_ctnr.b.y);
}
