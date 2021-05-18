use std::{
    sync::{mpsc, Arc, Mutex},
    thread,
    time::Duration,
};

fn main() {
    let m = Mutex::new(5);
    {
        let mut num = m.lock().unwrap();
        *num += 1;
    }
    println!("m = {:?}", m);

    let counter = Arc::new(Mutex::new(0));
    let mut handles = vec![];

    for _ in 0..10 {
        let counter = Arc::clone(&counter);
        let handle = thread::spawn(move || {
            let mut num = counter.lock().unwrap();
            *num += 1;
            thread::sleep(Duration::from_millis(100));
        });
        handles.push(handle);
    }

    for handle in handles {
        handle.join().unwrap();
    }

    println!("Result: {}", counter.lock().unwrap());

    let (tx, rx) = mpsc::channel();

    // let v = vec![-3, -2, -1];
    // let mut c = 0;
    // let handle = ;
    let tx1 = tx.clone();

    thread::spawn(move || {
        for i in 1..3 {
            // c += 1;
            // println!("hi number {} from the spawned thread!, v={:?}", c, v);
            thread::sleep(Duration::from_millis(1));
            tx.send(format!("hi {}", i)).unwrap();
        }
    });

    thread::spawn(move || {
        for i in 4..6 {
            // c += 1;
            // println!("hi number {} from the spawned thread!, v={:?}", c, v);
            thread::sleep(Duration::from_millis(1));
            tx1.send(format!("hi {}", i)).unwrap();
        }
    });

    // for _ in 1..5 {
    //     c += 1;
    //     println!("hi number {} from the main thread! v={:?}", c, v);
    //     thread::sleep(Duration::from_millis(1));
    // }

    // handle.join().unwrap();
    // tx.send("hi").unwrap();
    println!("main received: {}", rx.recv().unwrap());
    for received in rx {
        println!("main received: {}", received);
    }
}
