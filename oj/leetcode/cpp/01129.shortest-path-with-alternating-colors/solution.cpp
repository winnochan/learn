// Created by WinnoChan at 2024/05/06 01:22
// leetgo: 1.4.5
// https://leetcode.cn/problems/shortest-path-with-alternating-colors/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> dist(n, -1);
        dist[0] = 0;
        vector<vector<int>> redGraph(n), blueGraph(n);
        for (const auto& edge : redEdges) {
            redGraph[edge[0]].push_back(edge[1]);
        }
        for (const auto& edge : blueEdges) {
            blueGraph[edge[0]].push_back(edge[1]);
        }
        bfs(n, 1, redGraph, blueGraph, dist);
        bfs(n, 0, redGraph, blueGraph, dist);
        return dist;
    }

    void bfs(int n, int red, vector<vector<int>>& redGraph, vector<vector<int>>& blueGraph, vector<int>& dist) {
        vector<int> que(2 * n, 0);
        vector<int> redVis(n, 0);
        vector<int> blueVis(n, 0);
        if (red) {
            redVis[0] = 1;
        } else {
            blueVis[0] = 1;
        }
        int left = 0, right = 1, step = 1, temp, u;
        while (left < right) {
            temp = right;
            for (int i = left; i < temp; i++) {
                u = que[i];
                if (red) {
                    for (const auto& v: redGraph[u]) {
                        if (redVis[v]) {
                            continue;
                        }
                        redVis[v] = 1;
                        // cout << (red ? "red" : "blue") << ": " << step << " " << u << " -> " << v << '\n';
                        if (dist[v] < 0) {
                            dist[v] = step;
                        } else {
                            dist[v] = min(dist[v], step);
                        }
                        que[right++] = v;
                    }
                } else {
                    for (const auto& v: blueGraph[u]) {
                        if (blueVis[v]) {
                            continue;
                        }
                        blueVis[v] = 1;
                        // cout << (red ? "red" : "blue") << ": " << step << " " << u << " -> " << v << '\n';
                        if (dist[v] < 0) {
                            dist[v] = step;
                        } else {
                            dist[v] = min(dist[v], step);
                        }
                        que[right++] = v;
                    }
                }
            }
            red = !red;
            left = temp;
            step++;
        }
    }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  int n;
  LeetCodeIO::scan(cin, n);
  vector<vector<int>> redEdges;
  LeetCodeIO::scan(cin, redEdges);
  vector<vector<int>> blueEdges;
  LeetCodeIO::scan(cin, blueEdges);

  Solution *obj = new Solution();
  auto res = obj->shortestAlternatingPaths(n, redEdges, blueEdges);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
