// cargo run --bin arrays

fn main() {
    let fixed_len_arr = [1, 2, 3];
    for i in fixed_len_arr {
        print!("{i}-");
    }
    println!();

    let mut vec = Vec::<f32>::new();
    for i in 0i8..10 {
        vec.push(f32::from(i));
    }

    vec.push(2.0);
    println!("{:?}", vec)
}
