function stringifyNumbers(obj) {
  if (!Array.isArray(obj)) {
    obj = Object.assign({}, obj);
  } else {
    obj = obj.slice();
  }

  for (let k in obj) {
    let v = obj[k];

    if (v instanceof Object) {
      obj[k] = stringifyNumbers(v);
    } else if (Number.isInteger(v)) {
      obj[k] =  v.toString();
    }
  }
  return obj;
}

let obj = {
  num: 1,
  test: [],
  data: {
    val: 4,
    info: {
      isRight: true,
      random: 66
    }
  }
}

// console.log(obj);
console.log(
  stringifyNumbers(obj),
);
// console.log(obj);
