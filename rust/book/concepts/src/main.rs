fn main() {
    let a = 5;
    let b = &&&a;
    let &&&(mut c) = b;
    let d = c;
    c = 6;
    println!("The reference value of a is: {}, {}, {}", b, c, d);

    // immutable
    let x = 5;
    println!("The value of x is: {}", x);
    // x = 6;
    // println!("The value of x is: {}", x);

    let mut x = 5;
    println!("The value of x is: {}", x);
    x = 6;
    println!("The value of x is: {}", x);

    // shadowing
    let x = x + 1;
    let x = x + 2;
    println!("The value of x is: {}", x);

    let spaces = "   ";
    let spaces = spaces.len();
    println!("The length of spaces is: {}", spaces);

    // Data Types
    let guess: u32 = "42".parse().expect("Not a number!");
    println!("The guess number is: {}", guess);

    let x = 2.0;
    let y: f32 = 3.0;
    let z = 4.0f32;
    println!("The float numbers are: x={}, y={}, z={}", x, y, z);

    // addition
    let sum = 5 + 10;
    // subtraction
    let difference = 95.5 - 4.3;
    // multiplication
    let product = 4 * 30;
    // division
    let quotient = 56.7 / 32.2;

    // remainder
    let remainder = 43 % 5;
    println!(
        "The numeric operation results are: sum={}, difference={}, product={}, quotient={}, remainder={}",
        sum, difference, product, quotient, remainder
    );

    // bool type
    let t = true;
    let f: bool = false;
    println!("The bool vars are: t={}, f={}", t, f);

    // character type
    let c = 'z';
    let z = 'ℤ';
    let heart_eyed_cat = '😻';
    println!(
        "The char vars are: c={}, z={}, cat={}",
        c, z, heart_eyed_cat
    );

    // tuple type
    let tup: (i32, f64, u8) = (500, 6.4, 1);
    let (t1, t2, t3) = tup;
    println!("The tuple var is: ({}, {}, {})", t1, t2, t3);

    let arr: [i32; 5] = [1, 2, 3, 4, 5];
    let [a1, a2, a3, a4, a5] = arr;
    println!(
        "Thee array var is: [{}, {}, {}, {}, {}]",
        a1, a2, a3, a4, a5
    );

    func1();
    func2(5);
    func3(5, 6);

    let x = 5;
    let y = {
        let x = 3;
        x + 1
    };
    println!("The values are: x={}, y={}", x, y);

    let x = five();
    println!("The value of x is: {}", x);

    let x = plus_one(5);
    println!("The value of x is: {}", x);

    let number = 3;
    if number < 5 {
        println!("condition was true");
    } else {
        println!("condition was false");
    }

    // must be bool type
    // if number {
    //     println!("number was three");
    // }

    let number = 6;
    if number % 4 == 0 {
        println!("number is divisible by 4");
    } else if number % 3 == 0 {
        println!("number is divisible by 3");
    } else if number % 2 == 0 {
        println!("number is divisible by 2");
    } else {
        println!("number is not divisible by 4, 3, or 2");
    }

    let condition = true;
    let number = if condition { 5 } else { 6 };
    println!("The value of number is: {}", number);

    // loop {
    //     println!("again!");
    // }

    let mut counter = 0;
    let result = loop {
        counter += 1;
        if counter == 10 {
            break counter * 2;
        }
    };
    println!("The result is {}", result);

    let mut number = 3;
    while number != 0 {
        println!("{}!", number);
        number -= 1;
    }
    println!("LIFTOFF!!!");

    let a = [10, 20, 30, 40, 50];
    for element in a.iter() {
        println!("the value is: {}", element);
    }

    for number in (0..a.len()).rev() {
        println!("{}!", number);
    }
    println!("LIFTOFF!!!");
}

fn func1() {
    println!("Another function.");
}

fn func2(x: i32) {
    println!("The value of x is: {}", x);
}

fn func3(x: i32, y: i32) {
    println!("The value of x is: {}, y is: {}", x, y);
}

fn five() -> i32 {
    5
}

fn plus_one(x: i32) -> i32 {
    x + 1
}
