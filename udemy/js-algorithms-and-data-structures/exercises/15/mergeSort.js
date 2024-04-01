const merge = (arr1, arr2, cmpFunc) => {
  let arr = [], j = 0, k = 0;

  while (j < arr1.length && k < arr2.length) {
    let compareResult;
    if (typeof cmpFunc === 'function') {
      compareResult = cmpFunc(arr1[j], arr2[k]);
    } else {
      compareResult = arr1[j] <= arr2[k];
    }

    if (compareResult) {
      arr.push(arr1[j++]);
    } else {
      arr.push(arr2[k++]);
    }
  }

  if (j < arr1.length) arr.push(...arr1.slice(j));
  if (k < arr2.length) arr.push(...arr2.slice(k));

  return arr;
};

const mergeSort = (arr, cmpFunc) => {
  if (arr.length <= 1) return arr;

  let m = Math.floor(arr.length / 2);

  return merge(mergeSort(arr.slice(0, m), cmpFunc), mergeSort(arr.slice(m), cmpFunc));
}

console.log(merge([1,3,4,9], [2,6,7,8]));
console.log(mergeSort([1,3,4,9,2,6,7,8]));
