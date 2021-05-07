use std::fmt::{Display, Formatter, Result};

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
