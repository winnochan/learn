use std::env;

fn main() {
    println!("{}", env::var("CASE_INSENSITIVE").is_ok());

    let v = Vector::<i32, 4> { list: [1, 2, 3, 4] };
    println!("{:?}", v);

    let v = vec![1, 2, 3];
    println!("{:?}", v.iter().map(|x| x + 1).collect::<Vec<_>>());

    let c = Counter::new();
    for i in c {
        println!("i={}", i);
    }

    println!(
        "sum={}",
        Counter::new()
            .zip(Counter::new().skip(1))
            .map(|(a, b)| a * b)
            .filter(|x| x % 3 == 0)
            .sum::<u32>()
    )
}

#[derive(Debug)]
struct Vector<T, const L: usize> {
    list: [T; L],
}

#[derive(Debug)]
struct Counter {
    count: u32,
}

impl Counter {
    fn new() -> Counter {
        Counter { count: 0 }
    }
}

impl Iterator for Counter {
    type Item = u32;
    fn next(&mut self) -> Option<Self::Item> {
        if self.count < 5 {
            self.count += 1;
            Some(self.count)
        } else {
            None
        }
    }
}

// #[derive(PartialEq, Debug)]
// struct Shoe {
//     size: u32,
//     style: String,
// }

// fn shoes_in_size(shoes: Vec<Shoe>, shoe_size: u32) -> Vec<Shoe> {
//     shoes.into_iter().filter(|s| s.size == shoe_size).collect()
// }

// #[cfg(test)]
// mod tests {
//     use super::*;

//     #[test]
//     fn filters_by_size() {
//         let shoes = vec![
//             Shoe {
//                 size: 10,
//                 style: String::from("sneaker"),
//             },
//             Shoe {
//                 size: 13,
//                 style: String::from("sandal"),
//             },
//             Shoe {
//                 size: 10,
//                 style: String::from("boot"),
//             },
//         ];

//         let in_my_size = shoes_in_size(shoes, 10);

//         assert_eq!(
//             in_my_size,
//             vec![
//                 Shoe {
//                     size: 10,
//                     style: String::from("sneaker")
//                 },
//                 Shoe {
//                     size: 10,
//                     style: String::from("boot")
//                 },
//             ]
//         );
//     }
// }
