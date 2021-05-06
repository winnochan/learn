use std::usize;

fn main() {
    let s = "hello";
    println!("{}", s);
    let mut s = String::from("hello");
    s.push_str(", world");
    println!("{}", s);

    let s1 = "hello";
    let s2 = s1;
    println!("{}, {}", s1, s2);

    let s1 = String::from("hello");
    let s2 = s1.clone();
    println!("{}, {}", s1, s2);

    takes_ownership(s1);
    // s1's value moves into the function, and so is no longer valid here
    // println!("{}", s1);

    let x = 5;
    makes_copy(x);
    println!("{}", x);

    let s1 = gives_ownership();
    let s2 = String::from("takes and give back");
    let s3 = takes_and_gives_back(s2);
    println!("{}, {}", s1, s3);

    let s1 = String::from("hello");
    let len = calculate_length(&s1);
    println!("The length of '{}' is {}.", s1, len);

    let mut s1 = String::from("hello");
    change(&mut s1);
    println!("The changed s1 is {}.", s1);

    let mut s = String::from("hello");
    // can have only one mutable reference to a particular piece of data in a particular scope
    // let r1 = &mut s;
    {
        let r1 = &mut s;
        println!("{}", r1);
    } // r1 goes out of scope here, so we can make a new reference with no problems.
    let r2 = &mut s;
    println!("{}", r2);

    let r1 = &s; // no problem
    let r2 = &s; // no problem
                 // let r3 = &mut s;
    println!("{}, {}", r1, r2);
    let r3 = &mut s;
    println!("{}", r3);

    let mut s = String::from("hello world");
    let word = first_word(&s); // word will get the value 5
    s.clear();
    println!("{},{}", s, word);
}

fn takes_ownership(s: String) {
    println!("{}", s);
}

fn makes_copy(i: i32) {
    println!("{}", i);
}

fn gives_ownership() -> String {
    let s = String::from("gives ownership");
    s
}

fn takes_and_gives_back(s: String) -> String {
    s
}

fn calculate_length(s: &String) -> usize {
    s.len()
}

fn change(s: &mut String) {
    s.push_str(", world")
}

fn first_word(s: &String) -> usize {
    let bytes = s.as_bytes();
    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return i;
        }
    }
    s.len()
}
