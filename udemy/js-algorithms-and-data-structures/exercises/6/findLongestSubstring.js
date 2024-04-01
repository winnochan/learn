
// uncomment to see the processing procedure
function findLongestSubstring(str) {
  // console.log(str);

  let left = 0, right = 0, len =  0, max = 0, charMap = {};

  while (left <= right && right < str.length) {
    let char = str[right];
    if (!charMap.hasOwnProperty(char)) {
      // set the index of new char to object if the object doest not own it
      charMap[char] = right++;

      // update the max length
      max = Math.max(++len, max);

      // console.log("add", charMap, str.slice(left, right), str[left], str[right], max);
    } else {
      // remove all chars before the duplicated char
      for (let i = left; i < charMap[char]; i++) {
        delete charMap[str[i]];
      }

      // update the left and right index
      // make the substring between left and right does not have duplicated chars
      left = charMap[char] + 1;
      charMap[char] = right++;

      // update current substring length
      len = right - left;

      // console.log("sub", charMap, str.slice(left, right), str[left], str[right], max);
    }
  }

  return max;
}

console.log(
  findLongestSubstring(''),  // 0
  findLongestSubstring('rithmschool'),  // 7
  findLongestSubstring('thisisawesome'),  // 8
  findLongestSubstring('thecatinthehat'),  // 7
  findLongestSubstring('bbbbbb'),  // 1
  findLongestSubstring('longestsubstring'),  // 8
  findLongestSubstring('thisisshowwediot'),  // 6
);
