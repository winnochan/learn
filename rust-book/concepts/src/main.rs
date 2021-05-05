fn main() {
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
}
