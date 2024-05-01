// Created by WinnoChan at 2024/05/01 16:25
// leetgo: 1.4.5
// https://leetcode.cn/problems/find-eventual-safe-states/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        // 反向图
        vector<vector<int>> antig(n);
        // 记录出度
        vector<int> deg(n, 0);
        for (int u = 0; u < n; u++) {
            for (const auto& v: graph[u]) {
                antig[v].push_back(u);
                deg[u]++;
            }
        }
        vector<int> ans;
        stack<int> sta;
        for (int i = 0; i < n; i++) {
            if (!deg[i]) {
                sta.push(i);
            }
        }
        while (!sta.empty()) {
            auto u = sta.top();
            sta.pop();
            ans.push_back(u);
            for (const auto& v: antig[u]) {
                deg[v]--;
                if (!deg[v]) {
                    sta.push(v);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }

    void printVec(vector<int>& vec) {
        for (const auto& val : vec) {
            cout << val << ' ';
        }
        cout << '\n';
    }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<vector<int>> graph;
  LeetCodeIO::scan(cin, graph);

  Solution *obj = new Solution();
  auto res = obj->eventualSafeNodes(graph);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
