function nestedEvenSum(obj) {
  let evenNum = 0;
  for (let k in obj) {
    v = obj[k];
    if (v instanceof Object) {
      evenNum += nestedEvenSum(v);
    } else if (Number.isInteger(v) && v % 2 === 0) {
      evenNum += v;
    }
  }
  return evenNum;
}

var obj1 = {
  outer: 2,
  obj: {
    inner: 2,
    otherObj: {
      superInner: 2,
      notANumber: true,
      alsoNotANumber: "yup"
    }
  }
}

var obj2 = {
  a: 2,
  b: {b: 2, bb: {b: 3, bb: {b: 2}}},
  c: {c: {c: 2}, cc: 'ball', ccc: 5},
  d: 1,
  e: {e: {e: 2}, ee: 'car'}
};

console.log(
  nestedEvenSum(obj1),
  nestedEvenSum(obj2),
);
