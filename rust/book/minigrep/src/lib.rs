use std::{env, error, fs};

#[derive(Debug)]
pub struct Config {
    pub query: String,
    pub filename: String,
}

impl Config {
    // pub fn new(args: &[String]) -> Result<Config, &str> {
    //     if args.len() < 3 {
    //         return Err("not enough arguments");
    //     }
    //     Ok(Config {
    //         query: args[1].clone(),
    //         filename: args[2].clone(),
    //     })
    // }

    pub fn new(mut args: env::Args) -> Result<Config, &'static str> {
        args.next();
        let query = match args.next() {
            Some(arg) => arg,
            None => return Err("Didn't get a query string"),
        };
        let filename = match args.next() {
            Some(arg) => arg,
            None => return Err("Didn't get a file name"),
        };

        Ok(Config { query, filename })
    }
}

pub fn run(config: &Config) -> Result<(), Box<dyn error::Error>> {
    let Config { filename, .. } = config;
    let contents = fs::read_to_string(filename)?;
    println!("With text:\n{}", contents);
    Ok(())
}
