// function productOfArray(arr) {
//   if (!Array.isArray(arr) || !arr.length) return null;

//   if (arr.length === 1) return arr[0];

//   return arr[0] * productOfArray(arr.slice(1));
// }

function productOfArray(arr) {
  if (!Array.isArray(arr) || !arr.length) return null;

  if (arr.length === 1) return arr[0];

  return arr.pop() * productOfArray(arr);
}

console.log(
  productOfArray([2]),
  productOfArray([3, 4]),
  productOfArray([]),
  productOfArray([3, 5, 7]),
);
