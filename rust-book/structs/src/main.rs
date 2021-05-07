use std::fmt::{Display, Formatter, Result};

fn main() {
    let user1 = User {
        username: String::from("test"),
        email: String::from("test@email"),
        sign_in_count: 4,
        active: true,
    };
    println!("{}", user1);

    let t = r#"{}{"123"}""#;
    println!("{}", t);

    println!("{}", build_user("test2@email".to_string(), "test2".to_string()));

    let user2 = User {
        username: String::from("test3"),
        email: String::from("test3@email"),
        ..user1
    };
    println!("{}", user2);

    println!("{}", Color(0, 0, 0));
    println!("{}", Point(1, 1, 1));
    println!("{}", Null());

    println!("{}", area(12, 12));
    println!("{}", area_tuple((12, 12)));

    let rec = Rec { w: 12, h: 12 };
    println!("{:#?}: {}, {}", rec, area_structs(&rec), rec.area());
}

fn build_user(email: String, username: String) -> User {
    User {
        username,
        email,
        active: true,
        sign_in_count: 1,
    }
}

struct User {
    username: String,
    email: String,
    sign_in_count: u64,
    active: bool,
}

impl Display for User {
    fn fmt(&self, f: &mut Formatter<'_>) -> Result {
        write!(
            f,
            "{{ username: {}, email: {}, sign_in_count: {}, active: {} }}",
            self.username, self.email, self.sign_in_count, self.active
        )
    }
}

struct Color(u16, u16, u16);
struct Point(i32, i32, i32);
struct Null();
#[derive(Debug)]
struct Rec {
    w: u32,
    h: u32,
}

impl Display for Color {
    fn fmt(&self, f: &mut Formatter<'_>) -> Result {
        write!(f, "({}, {}, {})", self.0, self.1, self.2)
    }
}

impl Display for Point {
    fn fmt(&self, f: &mut Formatter<'_>) -> Result {
        write!(f, "({}, {}, {})", self.0, self.1, self.2)
    }
}

impl Display for Null {
    fn fmt(&self, f: &mut Formatter<'_>) -> Result {
        write!(f, "()")
    }
}

impl Display for Rec {
    fn fmt(&self, f: &mut Formatter<'_>) -> Result {
        write!(f, "({}, {})", self.w, self.h)
    }
}

fn area(w: u32, h: u32) -> u32 {
    w * h
}

fn area_tuple(wh: (u32, u32)) -> u32 {
    wh.0 * wh.1
}

fn area_structs(rec: &Rec) -> u32 {
    rec.w * rec.h
}

impl Rec {
    fn area(&self) -> u32 {
        self.w * self.h
    }
}
