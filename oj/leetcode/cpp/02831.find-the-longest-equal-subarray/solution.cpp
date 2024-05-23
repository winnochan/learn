// Created by WinnoChan at 2024/05/23 23:45
// leetgo: 1.4.7
// https://leetcode.cn/problems/find-the-longest-equal-subarray/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  int longestEqualSubarray(vector<int> &nums, int k) {
    int ans = 1;
    int n = nums.size();
    unordered_map<int, deque<int>> umap{};
    for (int i = 0; i < n; i++) {
      auto &deq = umap[nums[i]];
      deq.push_back(i);
      int cnt = deq.size();
      if (cnt <= 1) {
        continue;
      }
      int left = deq.front();
      int right = deq.back();
      if (right - left + 1 <= cnt + k) {
        ans = max(ans, cnt);
      } else {
        deq.pop_front();
        cnt--;
        while (right - deq.front() + 1 > cnt + k) {
          deq.pop_front();
          cnt--;
        }
        ans = max(ans, cnt);
      }
    }

    return ans;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> nums;
  LeetCodeIO::scan(cin, nums);
  int k;
  LeetCodeIO::scan(cin, k);

  Solution *obj = new Solution();
  auto res = obj->longestEqualSubarray(nums, k);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
