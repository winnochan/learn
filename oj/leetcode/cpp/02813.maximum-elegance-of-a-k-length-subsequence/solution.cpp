// Created by WinnoChan at 2024/06/13 23:58
// leetgo: 1.4.7
// https://leetcode.cn/problems/maximum-elegance-of-a-k-length-subsequence/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

template <typename T> ostream& operator<<(ostream& out, vector<T>& _vec) {
    auto it = _vec.begin();
    cout << "[";
    for (; it != _vec.end(); ++it) {
        out << *it;
        if (it + 1 != _vec.end()) {
            cout << ",";
        }
    }
    cout << "]";
    return out;
}

class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        int n = items.size();
        sort(items.begin(), items.end(),
             [&items](auto& vi, auto& vj) -> bool { return vi[0] > vj[0]; });

        unordered_set<int> cates{};
        cates.reserve(n);

        stack<int> st{};
        long long totalProfit = 0;
        for (int i = 0; i < k; ++i) {
            totalProfit += items[i][0];
            if (cates.count(items[i][1])) {
                st.push(items[i][0]);
            } else {
                cates.emplace(items[i][1]);
            }
        }
        if (cates.size() == k) {
            return totalProfit + (long long)k * k;
        }

        long long sz = cates.size();
        long long ans = totalProfit + sz * sz;
        for (int i = k; i < n; ++i) {
            if (st.empty()) break;
            if (cates.count(items[i][1])) continue;

            totalProfit += items[i][0] - st.top();
            st.pop();
            cates.emplace(items[i][1]);
            sz++;
            ans = max(ans, totalProfit + sz * sz);
        }
        return ans;
    }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<vector<int>> items;
  LeetCodeIO::scan(cin, items);
  int k;
  LeetCodeIO::scan(cin, k);

  Solution *obj = new Solution();
  auto res = obj->findMaximumElegance(items, k);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
