function collectStrings(obj) {
  let result = [];

  for (let k in obj) {
    let v = obj[k];

    if (typeof v === 'string') {
      result.push(v);
    } else if (v instanceof Object) {
      result.push(...collectStrings(v));
    }
  }
  return result;
}

const obj = {
  stuff: "foo",
  data: {
    val: {
      thing: {
        info: "bar",
        moreInfo: {
          evenMoreInfo: {
            weMadeIt: "baz"
          }
        }
      }
    }
  }
}

console.log(
  collectStrings(obj),
);
