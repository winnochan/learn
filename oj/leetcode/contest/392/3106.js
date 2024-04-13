/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var getSmallestString = function (s, k) {
  let sarr = s.split("");

  for (let i = 0; i < sarr.length; i++) {
    if (k <= 0) break;

    let d = getDist("a", sarr[i]);
    // console.log(d, k);
    if (!d) {
      continue;
    }
    if (d <= k) {
      k -= d;
      sarr[i] = "a";
    } else {
      sarr[i] = String.fromCharCode(sarr[i].charCodeAt(0) - k);
      k = 0;
    }
  }

  return sarr.join("");
};

function getDist(a, b) {
  let ca = a.charCodeAt(0);
  let cb = b.charCodeAt(0);
  let d1 = cb - ca;
  let d2 = 26 - (cb - ca);
  return Math.min(d1, d2);
}

console.log(getSmallestString("zbbz", 3));
console.log(getSmallestString("xaxcd", 4));
console.log(getSmallestString("lol", 0));
