use std::{fmt::Display, ops::Deref};

use List::{Cons, Null};

fn main() {
    let b = Box::new(5);
    println!("b={}", b);

    let list = Cons(1, Box::new(Cons(2, Box::new(Cons(3, Box::new(Null))))));
    println!("list={:?}", list);

    let x = 5;
    let y = MyBox::new(x);
    assert_eq!(5, x);
    assert_eq!(5, *y);

    let m = MyBox::new(String::from("Rust"));
    hello(&m);
}

#[derive(Debug)]
enum List {
    Cons(i32, Box<List>),
    Null,
}

#[derive(Debug)]
struct MyBox<T: Display>(T);

impl<T: Display> MyBox<T> {
    fn new(x: T) -> MyBox<T> {
        MyBox(x)
    }
}

impl<T: Display> Deref for MyBox<T> {
    type Target = T;
    fn deref(&self) -> &Self::Target {
        &self.0
    }
}

impl<T: Display> Drop for MyBox<T> {
    fn drop(&mut self) {
        println!("Dropping MyBox with data `{}`!", self.0);
    }
}

fn hello(name: &str) {
    println!("Hello, {}!", name);
}
