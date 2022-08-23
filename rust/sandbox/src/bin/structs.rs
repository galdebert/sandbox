//#![allow(non_snake_case)]

// https://doc.rust-lang.org/rust-by-example/fn/methods.html

struct Point2d {
    x: f32,
    y: f32,
}

impl Point2d {
    fn new(x: f32, y: f32) -> Point2d {
        Point2d { x, y }
    }

    // DO NOT USE fn sqlen(self) -> f32 {} because this *moves* self
    // `&self` is sugar for `self: &Self`, where `Self` is the type of the
    // caller object. In this case `Self` = `Rectangle`
    fn sqlen(&self) -> f32 {
        self.x * self.x + self.y * self.y
    }

    fn setx(&mut self, x: f32) {
        self.x = x
    }
}

fn main() {
    let mut q = Point2d::new(2.0, 2.0);

    println!("q_sqlen={}", q.sqlen());

    q.setx(3.0);

    println!("q_sqlen={}", q.sqlen());
}
