fn main() {
    let four = IpAddrKind::V4;
    let six = IpAddrKind::V6;
    println!("IP address kinds: {:?}, {:?}", four, six);

    let home = IpAddr {
        kind: IpAddrKind::V4,
        addr: String::from("127.0.0.1"),
    };
    let loopback = IpAddr {
        kind: IpAddrKind::V6,
        addr: String::from("::1"),
    };
    println!("{:?}, {:?}", home, loopback);

    let home = IpStr::V4(String::from("127.0.0.1"));
    let loopback = IpStr::V6(String::from("::1"));
    println!("{:?}, {:?}", home, loopback);

    let home = IpNum::V4(127, 0, 0, 1);
    let loopback = IpNum::V6(String::from("::1"));
    println!("{:?}, {:?}", home, loopback);

    let home = IpStruct::V4(Ipv4Addr {
        addr: String::from("127.0.0.1"),
    });
    let loopback = IpStruct::V6(Ipv6Addr {
        addr: String::from("::1"),
    });
    println!("{:?}, {:?}", home, loopback);

    // let five = Some(5);
    // let s = Some("string");
    // let opt: Option<i32> = None;
    // println!("{}, {}, {:?}", five, s, opt);

    println!("{}", value_in_cents(Coin::Penny));
    println!("{}", value_in_cents(Coin::Nickel));
    println!("{}", value_in_cents(Coin::Dime));
    println!("{}", value_in_cents(Coin::Quarter(UsState::Alabama)));
    println!("{}", value_in_cents(Coin::Quarter(UsState::Alaska)));

    let five = Some(5);
    println!("{}, {}", plus_one(five).is_some(), plus_one(None).is_none());

    let some_u8_value = 0u8;
    match some_u8_value {
        1 => println!("one"),
        3 => println!("three"),
        5 => println!("five"),
        7 => println!("seven"),
        _ => (),
    }

    let some_u8_value = Some(0u8);
    if let Some(3) = some_u8_value {
        println!("three");
    }
    if let Some(0) = some_u8_value {
        println!("zero");
    }

    let r = Refer { val: 123 };
    match r {
        ref v => println!("v={:?}", v),
    }
    println!("r={:?}", r);
}

#[derive(Debug)]
struct Refer {
    val: i32,
}

#[derive(Debug)]
enum IpAddrKind {
    V4,
    V6,
}

#[derive(Debug)]
struct IpAddr {
    kind: IpAddrKind,
    addr: String,
}

#[derive(Debug)]
enum IpStr {
    V4(String),
    V6(String),
}

#[derive(Debug)]
enum IpNum {
    V4(u8, u8, u8, u8),
    V6(String),
}

#[derive(Debug)]
struct Ipv4Addr {
    addr: String,
}

#[derive(Debug)]
struct Ipv6Addr {
    addr: String,
}

#[derive(Debug)]
enum IpStruct {
    V4(Ipv4Addr),
    V6(Ipv6Addr),
}

#[derive(Debug)]
enum UsState {
    Alabama,
    Alaska,
}

#[derive(Debug)]
enum Coin {
    Penny,
    Nickel,
    Dime,
    Quarter(UsState),
}

fn value_in_cents(coin: Coin) -> u8 {
    match coin {
        Coin::Penny => {
            println!("Lucky penny!");
            1
        }
        Coin::Nickel => 5,
        Coin::Dime => 10,
        Coin::Quarter(state) => {
            println!("State quarter from {:?}!", state);
            25
        }
    }
}

fn plus_one(n: Option<i32>) -> Option<i32> {
    match n {
        Some(i) => Some(i + 1),
        None => None,
    }
}
