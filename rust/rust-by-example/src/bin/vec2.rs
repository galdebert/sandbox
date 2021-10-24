// derive implementations
//
// pub trait Debug { fn fmt(&self, f: &mut Formatter<'_>) -> Result<(), Error>; }
//
// By default, variable bindings have move semantics
// However, if a type implements Copy, it instead has copy semantics
// https://doc.rust-lang.org/core/marker/trait.Copy.html
// https://doc.rust-lang.org/core/marker/trait.Copy.html#whats-the-difference-between-copy-and-clone
//
// a type that implements Copy has "Value semantics"
// a type that does not implement Copy has "Reference semantics"
//
#[derive(Debug, Copy, Clone)]
struct Vec2 {
  x: f64,
  y: f64,
}

impl Vec2 {
  fn sum_val(&self, other: Vec2) -> Vec2 {
    Vec2 { x: self.x + other.x, y: self.y + other.y } // no semicolon
  }

  fn add_val(&mut self, other: Vec2) {
    self.x = self.x + other.x;
    self.y = self.y + other.y; 
  }

  fn sum_ref(&self, other: &Vec2) -> Vec2 {
    Vec2 { x: self.x + (*other).x, y: self.y + (*other).y } // no semicolon
  }

  fn add_ref(&mut self, other: &Vec2) {
    self.x = self.x + (*other).x;
    self.y = self.y + (*other).y; 
  }
}


fn main() {
  let pos = Vec2 { x: 3.0, y: 5.0 };
  println!("\ndebug print\n{:?}", pos);
  println!("\npretty print\n{:#?}", pos);

  {
    let pos2 = Vec2 { x: 3.0, y: 5.0 };
    let mut pos3 = pos2.sum_ref(&pos);
    pos3.add_ref(&pos);
    pos3.add_ref(&pos2);
    println!("\ndebug print\n{:?}", pos3);
  }

  {
    let pos2 = Vec2 { x: 3.0, y: 5.0 };
    let mut pos3 = pos2.sum_val(pos);
    pos3.add_val(pos);
    pos3.add_val(pos2);
    println!("\ndebug print\n{:?}", pos3);

  }
}
