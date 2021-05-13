use minigrep::{run, Config};
use std::{env, process};

fn main() {
    let args: Vec<String> = env::args().collect();
    let config = Config::new(&args).unwrap_or_else(|err| {
        println!("Problem parsing arguments: {}", err);
        process::exit(1);
    });
    println!("{:?}", config);
    if let Err(e) = run(&config) {
        println!("Application error: {}", e);
        process::exit(1);
    }
}
