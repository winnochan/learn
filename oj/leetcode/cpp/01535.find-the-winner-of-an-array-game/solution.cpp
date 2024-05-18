// Created by WinnoChan at 2024/05/19 01:32
// leetgo: 1.4.5
// https://leetcode.cn/problems/find-the-winner-of-an-array-game/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  int getWinner(vector<int> &arr, int k) {
    int n = arr.size();
    if (k >= n - 1) {
      return *max_element(arr.begin(), arr.end());
    }

    int cnt = 0;
    int ans = arr[0];
    int i = 1;
    while (cnt < k) {
      if (arr[0] >= arr[i]) {
        cnt++;
      } else {
        arr[0] = arr[i];
        arr[i] = ans;
        ans = arr[0];
        cnt = 1;
      }

      i = i == n - 1 ? 1 : i + 1;
    }

    return ans;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> arr;
  LeetCodeIO::scan(cin, arr);
  int k;
  LeetCodeIO::scan(cin, k);

  Solution *obj = new Solution();
  auto res = obj->getWinner(arr, k);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
