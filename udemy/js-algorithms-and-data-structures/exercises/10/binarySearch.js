function binarySearch(arr, num) {
  if (!Array.isArray(arr) || !arr.length) return -1;

  function binarySearchHelper(l, r) {
    if (l === r) return arr[l] === num ? l : -1;

    let m = Math.floor((l + r) / 2);
    // console.log(`${l}: ${arr[l]}, ${m}: ${arr[m]}, ${r}: ${arr[r]}`);

    if (arr[m] === num) {
      return m;
    } else if (arr[m] > num) {
      return binarySearchHelper(l, m - 1);
    } else {
      return binarySearchHelper(m + 1, r);
    }
  }

  return binarySearchHelper(0, arr.length - 1);
}

console.log(
  binarySearch([], 7),
  binarySearch([1, 3, 5, 7, 9, 11], 7),
  binarySearch([1, 3, 11], 7),
  binarySearch([9, 8, 7, 6, 5, 4, 3, 2, 1], 10),
  binarySearch([100], 200),
  binarySearch([100], 100),
);
