pub mod house {
    #[derive(Debug)]
    pub struct BreakFirst {
        pub toast: String,
        fruit: String,
    }

    impl BreakFirst {
        pub fn summer(toast: &str, fruit: &str) -> BreakFirst {
            BreakFirst {
                toast: String::from(toast),
                fruit: String::from(fruit),
            }
        }
    }

    #[derive(Debug)]
    pub enum Appetizer {
        Soup,
        Salad,
    }

    pub mod hosting {
        pub fn add_to_waitlist() {
            println!("add_to_waitlist");
        }

        pub fn seat_at_table() {
            println!("seat_at_table");
            super::serving::serve_order();
        }
    }

    pub mod serving {
        pub fn take_order() {
            println!("take_order");
        }

        pub fn serve_order() {
            println!("serve_order");
        }

        pub fn take_payment() {
            println!("take_payment");
        }
    }
}
