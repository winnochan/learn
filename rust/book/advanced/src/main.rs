use std::slice;

fn main() {
    let mut num = 5;

    let r1 = &num as *const i32;
    let r2 = &mut num as *mut i32;

    println!("r1={:?}, r2={:?}", r1, r2);

    let address = 0x012345usize;
    let r = address as *const i32;
    println!("r={:?}", r);

    unsafe {
        println!("r1={},r2={}", *r1, *r2);

        dangerous();
    }

    let s = &mut vec![1, 2, 3, 4, 5, 6][..];
    println!("s={:?}", s);
    let (s1, s2) = split_at_mut(s, 3);
    println!("s1={:?},s2={:?}", s1, s2);
}

unsafe fn dangerous() {
    println!("dangerous function.");

    let mut num = 5;

    let r1 = &num as *const i32;
    let r2 = &mut num as *mut i32;
    println!("r1={},r2={}", *r1, *r2);
}

fn split_at_mut(s: &mut [i32], mid: usize) -> (&mut [i32], &mut [i32]) {
    let len = s.len();
    let ptr = s.as_mut_ptr();
    assert!(mid <= len);
    unsafe {
        (
            slice::from_raw_parts_mut(ptr, mid),
            slice::from_raw_parts_mut(ptr.add(mid), len - mid),
        )
    }
}
