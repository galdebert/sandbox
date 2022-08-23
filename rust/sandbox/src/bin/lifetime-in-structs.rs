// https://blog.logrocket.com/understanding-lifetimes-in-rust/

/*
References in structs can be a real hassle. You’re often better off avoiding them and using owned
values instead. That way, you don’t need to worry about references being invalidated and lifetimes
not lasting long enough. In my experience, it’s usually also what you want.

However, there are certain cases where structs with references are exactly what you want —
in particular, if you want to create a view into something else. Using structs with references is a
great way to organize some data into a package that’s easier to handle without moving or copying data.
This means that the original data source can still be referenced elsewhere and you’re spared the
hassle of cloning the data
*/

struct A {
    x: f32,
}

struct B<'t> {
    a: &'t A,
}

impl<'t> B<'t> {
    fn new(a: &'t A) -> B<'t> {
        return B { a };
    }
}

/*
impl B {
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
*/

fn main() {
    let a = A { x: 1.0 };
    let b = B::new(&a);

    println!("{}", b.a.x)
}
