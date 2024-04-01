function countUniqueValues(arr){
  if (!Array.isArray(arr) || !arr.length) return 0;

  let curValue = arr[0], uniq = 1;

  for (let i = 1; i < arr.length; i++) {
    if (curValue === arr[i]) continue;

    curValue = arr[i];
    uniq++;
  }

  return uniq;
}

console.log(
  countUniqueValues([-2, -1, -1, 0, 1]),
);
