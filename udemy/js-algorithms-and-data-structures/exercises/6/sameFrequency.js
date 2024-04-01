function sameFrequency(num1, num2){
  let arr1 = num1.toString().split('');
  let arr2 = num2.toString().split('');

  if (arr1.length !== arr2.length) return false;

  let num1Map = {}, num2Map = {};
  for (let char of arr1) {
    num1Map[char] = (num1Map[char] || 0) + 1;
  }
  for (let char of arr2) {
    if (!num1Map.hasOwnProperty(char)) {
      return false;
    }
    num2Map[char] = (num2Map[char] || 0) + 1;
  }
  if (num1Map.length !== num2Map.length) {
    return false;
  }
  for (let char in num1Map) {
    if (num1Map[char] !== num2Map[char]) {
      return false;
    }
  }
  return true;
}

console.log(
  sameFrequency(182, 281),
);
