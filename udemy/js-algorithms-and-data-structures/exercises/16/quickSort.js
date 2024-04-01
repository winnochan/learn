/**
 *
 *
 */
const quickSort = (arr, begin=0, end=arr.length) => {
  if (end - begin < 1) return arr;

  let cmpIndex = begin;
  let swapIndex = begin;
  for (let i = begin; i < end; i++) {
    if (i === cmpIndex) continue;

    if (arr[i] < arr[cmpIndex]) {
      swapIndex++;
      [arr[swapIndex], arr[i]] = [arr[i], arr[swapIndex]];
    }
  }
  [arr[cmpIndex], arr[swapIndex]] = [arr[swapIndex], arr[cmpIndex]];

  // console.log(swapIndex, arr[swapIndex], arr);

  quickSort(arr, begin, swapIndex);
  quickSort(arr, swapIndex + 1, end);

  return arr;
}

console.log(quickSort([1,3,4,9,2,6,7,8]));
