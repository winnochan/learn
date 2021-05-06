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
