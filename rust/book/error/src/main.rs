use std::{
    error,
    fs::{read_to_string, File},
    io::{Error, ErrorKind, Read},
};

fn main() -> Result<(), Box<dyn error::Error>> {
    // panic!("crash and burn");

    // let v = vec![1, 2, 3];
    // v[99];

    let path = "error.txt";
    let f = File::open(path);
    let f = match f {
        Ok(file) => file,
        Err(err) => match err.kind() {
            ErrorKind::NotFound => match File::create(path) {
                Ok(cfile) => cfile,
                Err(cerr) => panic!("Problem creating the file: {:?}", cerr),
            },
            other => {
                panic!("Problem opening the file: {:?}", other)
            }
        },
    };
    println!("{:?}", f);

    let path = "hello.txt";
    let f = File::open(path).unwrap_or_else(|error| {
        if error.kind() == ErrorKind::NotFound {
            File::create(path).unwrap_or_else(|error| {
                panic!("Problem creating the file: {:?}", error);
            })
        } else {
            panic!("Problem opening the file: {:?}", error);
        }
    });
    println!("{:?}", f);

    // let path = "world.txt";
    // // let f = File::open(path).unwrap();
    // let f = File::open(path).expect(&format!("Failed to open {}", path));
    // println!("{:?}", f);

    let s = match read_username_from_file("user.txt") {
        Ok(name) => name,
        Err(e) => panic!("Fail to read user name from {}, err={}", path, e),
    };
    println!("{}", s);

    let s = match easy_read_username_from_file("user.txt") {
        Ok(name) => name,
        Err(e) => panic!("Fail to read user name from {}, err={}", path, e),
    };
    println!("{}", s);

    let s = match very_easy_read_username_from_file("user.txt") {
        Ok(name) => name,
        Err(e) => panic!("Fail to read user name from {}, err={}", path, e),
    };
    println!("{}", s);

    let s = match read_to_string("user.txt") {
        Ok(name) => name,
        Err(e) => panic!("Fail to read user name from {}, err={}", path, e),
    };
    println!("{}", s);

    let s = read_to_string("user.txt")?;
    println!("{}", s);
    Ok(())
}

fn read_username_from_file(path: &str) -> Result<String, Error> {
    let f = File::open(path);

    let mut f = match f {
        Ok(file) => file,
        Err(e) => return Err(e),
    };

    let mut s = String::new();
    match f.read_to_string(&mut s) {
        Ok(_) => Ok(s),
        Err(e) => Err(e),
    }
}

fn easy_read_username_from_file(path: &str) -> Result<String, Error> {
    let mut f = File::open(path)?;
    let mut s = String::new();
    f.read_to_string(&mut s)?;
    Ok(s)
}

fn very_easy_read_username_from_file(path: &str) -> Result<String, Error> {
    let mut s = String::new();
    File::open(path)?.read_to_string(&mut s)?;
    Ok(s)
}
