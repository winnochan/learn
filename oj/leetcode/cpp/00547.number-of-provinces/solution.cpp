// Created by WinnoChan at 2024/05/01 04:44
// leetgo: 1.4.5
// https://leetcode.cn/problems/number-of-provinces/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class UnionFind {
public:
  UnionFind(int n) {
    root.resize(n);
    for (int i = 0; i < n; i++) {
      root[i] = i;
    }
  }

  int find(int x) {
    if (root[x] != x) {
      root[x] = find(root[x]);
    }
    return root[x];
  }

  void merge(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) return;
    root[fx] = fy;
  }
private:
  vector<int> root;
};

class Solution {
public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<bool> flag(n, false);
    UnionFind uf(n);
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        if (isConnected[i][j]) {
          uf.merge(i, j);
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int fi = uf.find(i);
      if (!flag[fi]) {
        flag[fi] = true;
        ans++;
      }
    }
    return ans;
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<vector<int>> isConnected;
  LeetCodeIO::scan(cin, isConnected);

  Solution *obj = new Solution();
  auto res = obj->findCircleNum(isConnected);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
