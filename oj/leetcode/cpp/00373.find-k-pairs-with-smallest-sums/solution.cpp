// Created by WinnoChan at 2024/05/24 00:19
// leetgo: 1.4.7
// https://leetcode.cn/problems/find-k-pairs-with-smallest-sums/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

struct Pair {
    int v;
    int i;
    int j;
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                       int k) {
        vector<vector<int>> ans(k);

        priority_queue<Pair, vector<Pair>, function<bool(Pair&, Pair&)>> pq(
            [](Pair& a, Pair& b) -> bool {
                if (a.v > b.v) {
                    return true;
                } else if (a.v < b.v) {
                    return false;
                } else {
                    if (a.i > b.i) {
                        return true;
                    }
                    return false;
                }
            });

        for (int i = 0; i < nums1.size(); i++) {
            pq.push(Pair{nums1[i] + nums2[0], i, 0});
        }

        for (int m = 0; m < k; m++) {
            auto& t = pq.top();
            ans[m] = {nums1[t.i], nums2[t.j]};
            if (t.j + 1 < nums2.size()) {
                pq.push(Pair{nums1[t.i] + nums2[t.j + 1], t.i, t.j + 1});
            }
            pq.pop();
        }

        return ans;
    }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> nums1;
  LeetCodeIO::scan(cin, nums1);
  vector<int> nums2;
  LeetCodeIO::scan(cin, nums2);
  int k;
  LeetCodeIO::scan(cin, k);

  Solution *obj = new Solution();
  auto res = obj->kSmallestPairs(nums1, nums2, k);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
