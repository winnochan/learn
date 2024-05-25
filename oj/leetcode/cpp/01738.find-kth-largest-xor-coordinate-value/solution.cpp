// Created by WinnoChan at 2024/05/26 02:28
// leetgo: 1.4.7
// https://leetcode.cn/problems/find-kth-largest-xor-coordinate-value/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  int kthLargestValue(vector<vector<int>> &matrix, int k) {
    priority_queue<int> pq{};

    int m = matrix.size();
    int n = matrix[0].size();
    pq.emplace(matrix[0][0]);
    for (int i = 1; i < m; i++) {
      matrix[i][0] ^= matrix[i - 1][0];
      pq.emplace(matrix[i][0]);
    }
    for (int i = 1; i < n; i++) {
      matrix[0][i] ^= matrix[0][i - 1];
      pq.emplace(matrix[0][i]);
    }
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        matrix[i][j] ^=
            matrix[i - 1][j] ^ matrix[i][j - 1] ^ matrix[i - 1][j - 1];
        pq.emplace(matrix[i][j]);
      }
    }
    for (int i = 1; i < k; i++) {
      pq.pop();
    }

    return pq.top();
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<vector<int>> matrix;
  LeetCodeIO::scan(cin, matrix);
  int k;
  LeetCodeIO::scan(cin, k);

  Solution *obj = new Solution();
  auto res = obj->kthLargestValue(matrix, k);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
