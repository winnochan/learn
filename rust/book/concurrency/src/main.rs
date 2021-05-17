use std::{thread, time::Duration};

fn main() {
    let v = vec![-3, -2, -1];
    let mut c = 0;
    let handle = thread::spawn(move || {
        for _ in 1..10 {
            c += 1;
            println!("hi number {} from the spawned thread!, v={:?}", c, v);
            thread::sleep(Duration::from_millis(1));
        }
    });

    // for _ in 1..5 {
    //     c += 1;
    //     println!("hi number {} from the main thread! v={:?}", c, v);
    //     thread::sleep(Duration::from_millis(1));
    // }

    handle.join().unwrap();
}
