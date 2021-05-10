use std::vec;

fn main() {
    let v: Vec<i32> = Vec::new();
    println!("v={:?}", v);
    let v = vec![1, 2, 3];
    println!("v={:?}", v);

    let mut v = Vec::new();
    v.push(5);
    v.push(6);
    v.push(7);
    v.push(8);
    println!("v={:?}", v);

    let val = &v[2];
    println!("val={:?}", val);

    let val = v.get(2);
    println!("val={:?}", val);

    for i in &v {
        println!("{}", i);
    }
    for i in &mut v {
        *i += 50;
        println!("{}", i);
    }
    println!("v={:?}", v);

    let v = vec![
        Element::Int(3),
        Element::Float(4.5),
        Element::Text(String::from("text")),
    ];
    println!("v={:?}", v);

    let s = String::new();
    println!("s={}", s);
    let data = "initial contents";
    let s = data.to_string();
    println!("s={}", s);
}

#[derive(Debug)]
enum Element {
    Int(i32),
    Float(f32),
    Text(String),
}
