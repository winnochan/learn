use chrono::prelude::*;
use std::collections::BinaryHeap;

fn main() {
    let cap = 20000000;
    // let mut heap: BinaryHeap<usize> = BinaryHeap::with_capacity(cap);
    let mut heap: BinaryHeap<usize> = BinaryHeap::new();
    let t = Local::now().timestamp_millis();
    for i in (0..cap).rev() {
        heap.push(i);
    }
    // for i in 0..cap {
    //     heap.push(i);
    // }
    let t = Local::now().timestamp_millis() - t;
    println!("push {} cost: {}ms", cap, t);
    let t = Local::now().timestamp_millis();
    for _ in 0..cap {
        heap.pop();
    }
    let t = Local::now().timestamp_millis() - t;
    println!("pop {} cost: {}ms", cap, t);
}
