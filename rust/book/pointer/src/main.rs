use List::{Cons, Null};

fn main() {
    let b = Box::new(5);
    println!("b={}", b);

    let list = Cons(1, Box::new(Cons(2, Box::new(Cons(3, Box::new(Null))))));
    println!("list={:?}", list);
}

#[derive(Debug)]
enum List {
    Cons(i32, Box<List>),
    Null,
}
