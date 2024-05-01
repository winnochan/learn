// Created by WinnoChan at 2024/05/01 21:40
// leetgo: 1.4.5
// https://leetcode.cn/problems/course-schedule-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<int> ans;
    vector<int> deg(numCourses);
    vector<vector<int>> graph(numCourses);
    stack<int> st;
    for (const auto &pair : prerequisites) {
      graph[pair[1]].push_back(pair[0]);
      deg[pair[0]]++;
    }
    for (auto i = 0; i < numCourses; i++) {
      if (!deg[i]) {
        st.push(i);
      }
    }
    while (!st.empty()) {
      int u = st.top();
      st.pop();
      ans.push_back(u);
      for (const auto &v : graph[u]) {
        deg[v]--;
        if (!deg[v]) {
          st.push(v);
        }
      }
    }
    return ans.size() == numCourses ? ans : vector<int>{};
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  int numCourses;
  LeetCodeIO::scan(cin, numCourses);
  vector<vector<int>> prerequisites;
  LeetCodeIO::scan(cin, prerequisites);

  Solution *obj = new Solution();
  auto res = obj->findOrder(numCourses, prerequisites);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
