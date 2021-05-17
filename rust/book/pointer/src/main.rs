use std::{fmt::Display, ops::Deref, rc::Rc};
use List::{Cons, Null};
use Node::{Next, None};

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

    let a = Rc::new(Next(5, Rc::new(Next(10, Rc::new(None)))));
    let b = Next(3, Rc::clone(&a));
    let c = Next(4, Rc::clone(&a));
    println!("a={:?},b={:?},c={:?}", a, b, c);

    let a = Rc::new(Next(5, Rc::new(Next(10, Rc::new(None)))));
    println!("count after creating a = {}", Rc::strong_count(&a));
    let b = Next(3, Rc::clone(&a));
    println!("count after creating b {:?} = {}", b, Rc::strong_count(&a));
    {
        let c = Next(4, Rc::clone(&a));
        println!("count after creating c {:?} = {}", c, Rc::strong_count(&a));
    }
    println!("count after c goes out of scope = {}", Rc::strong_count(&a));
}

#[derive(Debug)]
enum List {
    Cons(i32, Box<List>),
    Null,
}

#[derive(Debug)]
enum Node {
    Next(i32, Rc<Node>),
    None,
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
