struct Stuff {
    name: &'static str,
}

impl Drop for Stuff {
    fn drop(&mut self) {
        println!("dropping {}", self.name)
    }
}

fn main() {
    let _s1 = Stuff { name: "a" };
    println!("before move");
    let _s2 = _s1;
    println!("after move");
}
