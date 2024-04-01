function averagePair(arr, avg){
  if (arr.length <= 1) return false;

  let left = 0, right = arr.length - 1;
  while (left < right) {
    let tmp = (arr[left] + arr[right]) / 2;
    if (tmp === avg) return true;
    if (tmp > avg) right--;
    else left++;
  }
  return false;
}

console.log(
  averagePair([1, 2, 3], 2.5),
  averagePair([], 4),
);
