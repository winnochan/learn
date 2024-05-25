// Created by WinnoChan at 2024/05/24 01:36
// leetgo: 1.4.7
// https://leetcode.cn/problems/find-the-most-competitive-subsequence/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

typedef pair<int, int> PII;

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> ans{};
        for (int i = 0; i < n; i++) {
            while (ans.size() && nums[i] < ans.back() &&
                   ans.size() + n - i > k) {
                ans.pop_back();
            }
            if (ans.size() < k) {
                ans.emplace_back(nums[i]);
            }
        }

        return ans;
    }

    vector<int> nlogn(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<PII, vector<PII>, function<bool(PII&, PII&)>> pq(
            [&](PII& a, PII& b) -> bool {
                if (a.first > b.first) {
                    return true;
                } else if (a.first < b.first) {
                    return false;
                } else if (a.second > b.second) {
                    return true;
                } else {
                    return false;
                }
            });

        for (int i = 0; i <= n - k; i++) {
            pq.push({nums[i], i});
        }

        int rmi = -1;
        vector<int> ans{};

        for (int i = n - k + 1; i < n; i++) {
            while (ans.size() && pq.top().second <= rmi) {
                pq.pop();
            }
            rmi = pq.top().second;
            ans.push_back(pq.top().first);
            pq.pop();
            pq.push({nums[i], i});
        }
        while (ans.size() && pq.top().second <= rmi) {
            pq.pop();
        }
        ans.push_back(pq.top().first);

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
  auto res = obj->mostCompetitive(nums, k);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
