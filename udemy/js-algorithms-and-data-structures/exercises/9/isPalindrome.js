function isPalindrome(str) {
  if (str.length <= 1) return true;

  if (str[0] !== str[str.length - 1]) return false;

  return isPalindrome(str.slice(1, str.length - 1));
}

console.log(
  isPalindrome("123456"),
  isPalindrome("131415"),
  isPalindrome("12321"),
  isPalindrome("123321"),
);
