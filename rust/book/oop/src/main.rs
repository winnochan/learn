mod lib;
use crate::lib::{AveragedCollection, Button, Screen, SelectBox};

fn main() {
    let mut a = AveragedCollection::new();
    println!("a = {:?}", a);

    a.add(1);
    a.add(2);
    a.add(2);
    println!("a = {:?}", a);
    a.remove();
    println!("a = {:?}", a);

    println!("average = {}", a.average());

    let screen = Screen {
        components: vec![
            Box::new(Button {
                width: 50,
                height: 10,
                label: String::from("Ok"),
            }),
            Box::new(SelectBox {
                width: 100,
                height: 200,
                options: vec![String::from("Yes"), String::from("No")],
            }),
        ],
    };
    screen.run();
}
