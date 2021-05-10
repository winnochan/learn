use std::{collections::HashMap, vec};

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

    let hello = String::from("السلام عليكم");
    println!("hello={},length={}", hello, hello.len());
    let hello = String::from("Dobrý den");
    println!("hello={},length={}", hello, hello.len());
    let hello = String::from("Hello");
    println!("hello={},length={}", hello, hello.len());
    let hello = String::from("שָׁלוֹם");
    println!("hello={},length={}", hello, hello.len());
    let hello = String::from("नमस्ते");
    println!("hello={},length={}", hello, hello.len());
    let hello = String::from("こんにちは");
    println!("hello={},length={}", hello, hello.len());
    let hello = String::from("안녕하세요");
    println!("hello={},length={}", hello, hello.len());
    let hello = String::from("你好");
    println!("hello={},length={}", hello, hello.len());
    for c in hello.chars() {
        println!("c={}", c);
    }
    let hello = String::from("Olá");
    println!("hello={},length={}", hello, hello.len());
    let hello = String::from("Здравствуйте");
    println!("hello={},length={}", hello, hello.len());
    let hello = String::from("Hola");
    println!("hello={},length={}", hello, hello.len());

    let mut s1 = String::from("foo");
    let s2 = "bar";
    s1.push_str(s2);
    println!("s1={}, s2={}", s1, s2);

    let mut s = String::from("lo");
    s.push('l');
    println!("s={}", s);

    let s1 = String::from("Hello, ");
    let s2 = String::from("world!");
    // note s1 has been moved here and can no longer be used
    let s3 = s1 + &s2;
    println!("s3={},s2={}", s3, s2);

    let s1 = String::from("tic");
    let s2 = String::from("tac");
    let s3 = String::from("toe");
    let s = format!("{}-{}-{}", s1, s2, s3);
    println!("s={}", s);

    let mut scores = HashMap::new();
    scores.insert(String::from("Blue"), 10);
    scores.insert(String::from("Yellow"), 50);
    // scores.insert("Blue", 10);
    // scores.insert("Yellow", 50);
    println!("scores={:?}", scores);

    let teams = vec![String::from("Blue"), String::from("Yellow")];
    let initial_scores = vec![10, 50];
    let scores: HashMap<_, _> = teams.into_iter().zip(initial_scores.into_iter()).collect();
    println!("scores={:?}", scores);

    let mut scores = HashMap::new();

    scores.insert(String::from("Blue"), 10);
    scores.insert(String::from("Yellow"), 50);

    for (key, value) in &scores {
        println!("{}: {}", key, value);
    }
    println!("{:?}", scores.get(&String::from("Blue")));
    scores.insert(String::from("Blue"), 25);
    println!("scores={:?}", scores);
    scores.entry(String::from("Blue")).or_insert(70);
    println!("scores={:?}", scores);

    let text = "hello world wonderful world";
    let mut map = HashMap::new();
    for word in text.split_whitespace() {
        let count = map.entry(word).or_insert(0);
        *count += 1;
    }
    println!("{:?}", map);
}

#[derive(Debug)]
enum Element {
    Int(i32),
    Float(f32),
    Text(String),
}
