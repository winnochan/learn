// Created by WinnoChan at 2024/04/29 13:10
// leetgo: 1.4.5
// https://leetcode.cn/problems/sort-the-matrix-diagonally/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> arr(min(m, n), 0);
        for (int i = m - 1; i >= 0; i--) {
            int sz = min(m - i, n);
            for (int j = 0; j < sz; j++) {
                arr[j] = mat[i + j][j];
            }
            sort(arr.begin(), arr.begin() + sz);
            // printVec(arr);
            for (int j = 0; j < sz; j++) {
                mat[i + j][j] = arr[j];
            }
        }
        for (int i = 1; i < n; i++) {
            int sz = min(n - i, m);
            for (int j = 0; j < sz; j++) {
                arr[j] = mat[j][i + j];
            }
            sort(arr.begin(), arr.begin() + sz);
            // printVec(arr);
            for (int j = 0; j < sz; j++) {
                mat[j][i + j] = arr[j];
            }
        }
        return mat;
    }

    void printVec(vector<int>& vec) {
        for (const auto& v: vec) {
            cout << v << ' ';
        }
        cout << '\n';
    }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<vector<int>> mat;
  LeetCodeIO::scan(cin, mat);

  Solution *obj = new Solution();
  auto res = obj->diagonalSort(mat);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
