// Created by WinnoChan at 2024/06/04 01:52
// leetgo: 1.4.7
// https://leetcode.cn/problems/count-pairs-of-connectable-servers-in-a-weighted-tree-network/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size() + 1;
        vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>{});

        for (const auto& e: edges) {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }

        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            if (graph[i].size() <= 1) {
                continue;
            }

            vector<int> vis(n, 0);
            vis[i] = 1;
            vector<int> cnt(graph[i].size(), 0);

            for (int j = 0; j < graph[i].size(); j++) {
                dfs(graph, vis, cnt, graph[i][j].first, j, graph[i][j].second, signalSpeed);
            }

            int temp = 0;
            for (int j = 0; j < cnt.size(); j++) {
                for (int k = j + 1; k < cnt.size(); k++) {
                    temp += cnt[j] * cnt[k];
                }
            }
            ans[i] = temp;
        }

        return ans;
    }

    void dfs(vector<vector<pair<int, int>>>& graph, vector<int>& vis, vector<int>& cnt, int src, int dir, int dist, int sig) {
        vis[src] = 1;
        if (dist > 0 && dist % sig == 0) {
            cnt[dir]++;
        }

        for (const auto& p: graph[src]) {
            if (vis[p.first]) {
                continue;
            }
            dfs(graph, vis, cnt, p.first, dir, dist + p.second, sig);
        }
    }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<vector<int>> edges;
  LeetCodeIO::scan(cin, edges);
  int signalSpeed;
  LeetCodeIO::scan(cin, signalSpeed);

  Solution *obj = new Solution();
  auto res = obj->countPairsOfConnectableServers(edges, signalSpeed);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
