#[derive(Debug)]
struct Point2d {
    x: f32,
    y: f32,
}

#[derive(Debug)]
struct Polygon {
    exterior: Vec<Point2d>,
}

impl Polygon {
    // https://stackoverflow.com/questions/24977365/differences-in-type-inference-for-closures-and-functions-in-rust
    // Rust functions do not infer return type (but closures do)
    fn new() -> Polygon {
        Polygon {
            exterior: Vec::new(),
        }
    }

    fn push(&mut self, p: Point2d) {
        self.exterior.push(p)
    }
}

fn main() {
    let mut polygon = Polygon::new();
    polygon.push(Point2d { x: 0.0, y: 0.0 });
    println!("{:?}", polygon);
    println!("{} {}", polygon.exterior[0].x, polygon.exterior[0].y);
}
