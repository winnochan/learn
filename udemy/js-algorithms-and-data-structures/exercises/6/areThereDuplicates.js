function areThereDuplicates(...arr) {
  let haveMap = {};
  for (let item of arr) {
    if (haveMap.hasOwnProperty(item)) {
      return true;
    }

    haveMap[item] = 1;
  }
  return false;
}

console.log(
  areThereDuplicates(1, 2, 3),
  areThereDuplicates(1, 2, 2),
);
