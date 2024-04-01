function validAnagram(str1, str2){
  if (str1.length !== str2.length) return false;

  let charCounter1 = {};
  let charCounter2 = {};

  for (let char of str1) {
    charCounter1[char] = (charCounter1[char] || 0) + 1;
  }

  for (let char of str2) {
    if (!charCounter1.hasOwnProperty(char)) return false;

    charCounter2[char] = (charCounter2[char] || 0) + 1;
  }
  if (charCounter1.length !== charCounter2.length) return false;

  for (let char in charCounter1) {
    if (charCounter1[char] !== charCounter2[char]) return false;
  }

  return true;
}

console.log(
  validAnagram('qwerty', 'qeywrt'),
);
