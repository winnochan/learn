function isSubsequence(sub, str) {
  let o = 0;
  let i = 0;
  while (i < sub.length && o < str.length) {
    if (str[o] === sub[i]) {
      o++;
      i++;
    } else {
      o++;
    }
  }
  return i === sub.length;
}

console.log(
  isSubsequence('abc', 'acb'),
  isSubsequence('sing', 'string'),
);
