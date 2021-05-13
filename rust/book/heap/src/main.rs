use chrono::prelude::*;
use rand::Rng;
use std::collections::BinaryHeap;

fn main() {
    let cap = 20000000;
    let mut heap: BinaryHeap<u16> = BinaryHeap::new();
    let mut rng = rand::thread_rng();
    let t = Local::now().timestamp_millis();
    for _ in 0..cap {
        let r: u16 = rng.gen();
        heap.push(r);
    }
    let t = Local::now().timestamp_millis() - t;
    println!("push {} cost: {}ms", cap, t);
    let t = Local::now().timestamp_millis();
    for _ in 0..cap {
        heap.pop();
    }
    let t = Local::now().timestamp_millis() - t;
    println!("pop {} cost: {}ms", cap, t);
}
