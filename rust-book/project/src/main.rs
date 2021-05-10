use project::house::{
    hosting::{add_to_waitlist, seat_at_table},
    Appetizer, BreakFirst,
};

fn main() {
    add_to_waitlist();
    seat_at_table();
    project::house::serving::serve_order();

    let mut bf = BreakFirst::summer("a", "b");
    println!("{:?}", bf);
    bf.toast = String::from("c");
    // bf.fruit = String::from("d");
    // println!("{:?},{},{}", bf, bf.toast, bf.fruit);

    println!("{:?},{:?}", Appetizer::Soup, Appetizer::Salad);
}
