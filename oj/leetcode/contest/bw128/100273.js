/**
 * @param {number[]} nums
 * @return {number}
 */
var numberOfSubarrays = function (nums) {
  // return naive2(nums);
  nums = lisanhua(nums);

  let ans = 0;
  const it = new IndexTree(nums.length);
  for (let i = 0; i < nums.length; i++) {
    ans += 1 + it.sum(nums[i]);
    it.add(nums[i], 1);
  }

  return ans;
};

// function naive(nums) {
//   let ans = 0;
//   for (let i = 0; i < nums.length; i++) {
//     for (let j = i; j < nums.length; j++) {
//       if (nums[i] !== nums[j]) continue;
//       let flag = true;
//       for (let k = i; k <= j; k++) {
//         if (nums[k] > nums[i]) {
//           flag = false;
//           break;
//         }
//       }
//       if (flag) {
//         ans++;
//       }
//     }
//   }
//   return ans;
// }

// function naive2(nums) {
//   let map = new Map();
//   for (let i = 0; i < nums.length; i++) {
//     let v = nums[i];
//     if (!map.has(v)) {
//       map.set(v, []);
//     }
//     map.get(v).push(i);
//   }
//   let ans = 0;

//   for (const v of map.keys()) {
//     let is = map.get(v);
//     for (let i = 0; i < is.length; i++) {
//       for (let j = i; j < is.length; j++) {
//         let flag = true;
//         for (let k = is[i]; k <= is[j]; k++) {
//           if (nums[k] > v) {
//             flag = false;
//             break;
//           }
//         }
//         if (flag) {
//           ans++;
//         }
//       }
//     }
//   }
//   return ans;
// }

function lisanhua(nums) {
  let s = Array.from(new Set(nums)).sort((a, b) => b - a);
  let m = new Map();
  for (let i = 0; i < s.length; i++) {
    m.set(s[i], i + 1);
  }
  return nums.map((v) => m.get(v));
}

function jiecheng(n) {
  if (n <= 1) return 1;
  return n * jiecheng(n - 1);
}

class IndexTree {
  constructor(n) {
    this.cap = n;
    this.tree = new Array(n + 1).fill(0);
    this.num = new Array(n + 1).fill(0);
  }

  add(i, v) {
    while (i <= this.cap) {
      this.tree[i] += v;
      i += i & -i;
    }
    this.num[i] += v;
  }

  sum(i) {
    let ans = 0;
    while (i > 0) {
      ans += this.tree[i];
      i -= i & -i;
    }
    return ans;
  }
}

console.log(numberOfSubarrays([1, 4, 3, 3, 2]));
console.log(numberOfSubarrays([3, 3, 3]));
console.log(numberOfSubarrays([1]));
