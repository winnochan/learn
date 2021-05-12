fn main() {
    println!("Hello, world!");
}

#[derive(Debug)]
struct Rec {
    w: u32,
    h: u32,
}

impl Rec {
    fn can_hold(&self, other: &Rec) -> bool {
        self.w > other.w && self.h > other.h
    }
}

fn add_two(a: i32) -> i32 {
    a + 2
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        assert_eq!(2 + 2, 4);
    }

    #[test]
    fn it_fails() {
        assert_eq!(2 + 2, 3);
    }

    #[test]
    fn it_holds() {
        assert!(Rec { w: 8, h: 8 }.can_hold(&Rec { w: 6, h: 6 }));
    }

    #[test]
    fn it_adds() {
        assert_eq!(add_two(44), 46, "44 add 2 should be 46");
    }
}
