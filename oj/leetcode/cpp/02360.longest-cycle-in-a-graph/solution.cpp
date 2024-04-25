// Created by WinnoChan at 2024/04/26 04:19
// leetgo: 1.4.5
// https://leetcode.cn/problems/longest-cycle-in-a-graph/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        // 所有点的入度
        vector<int> deg(n);
        for (int i = 0; i < n; i++) {
            if (edges[i] >= 0) {
                deg[edges[i]]++;
            }
        }
        // 所有入度为0的节点
        deque<int> zeros;
        for (int i = 0; i < n; i++) {
            if (!deg[i]) {
                zeros.emplace_back(i);
            }
        }

        int u, v;
        while (zeros.size()) {
            u = zeros.front();
            zeros.pop_front();
            v = edges[u];
            if (v >= 0) {
                deg[v]--;
                if (!deg[v]) {
                    zeros.emplace_back(v);
                }
            }
        }

        int ans = -1;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(edges, vis, deg, i));
        }
        // printVec(deg);

        return ans;
    }

    int dfs(vector<int>& edges, vector<int>& vis, vector<int>& deg, int start) {
        if (vis[start]) return -1;
        if (!deg[start]) return -1;

        int ans = 1;
        int temp = start;
        vis[temp] = 1;
        while (edges[temp] >= 0 && edges[temp] != start) {
            ans++;
            temp = edges[temp];
            vis[temp] = 1;
        }
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

  vector<int> edges;
  LeetCodeIO::scan(cin, edges);

  Solution *obj = new Solution();
  auto res = obj->longestCycle(edges);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
