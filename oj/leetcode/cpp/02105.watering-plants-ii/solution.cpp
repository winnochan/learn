// Created by WinnoChan at 2024/05/09 23:39
// leetgo: 1.4.5
// https://leetcode.cn/problems/watering-plants-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
  int minimumRefill(vector<int> &plants, int capacityA, int capacityB) {
    int n = plants.size();
    int a = capacityA;
    int b = capacityB;
    int ans = 0;
    int left = 0;
    int right = n - 1;
    while (left < right) {
      if (a >= plants[left]) {
        a -= plants[left++];
      } else {
        ans++;
        a = capacityA - plants[left++];
      }
      if (b >= plants[right]) {
        b -= plants[right--];
      } else {
        ans++;
        b = capacityB - plants[right--];
      }
    }
    if (left == right && a < plants[left] && b < plants[right]) {
      ans++;
    }
    return ans;
  }

  void printVec(vector<int> &vec) {
    for (const auto &val : vec) {
      cout << val << '\t';
    }
    cout << '\n';
  }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> plants;
  LeetCodeIO::scan(cin, plants);
  int capacityA;
  LeetCodeIO::scan(cin, capacityA);
  int capacityB;
  LeetCodeIO::scan(cin, capacityB);

  Solution *obj = new Solution();
  auto res = obj->minimumRefill(plants, capacityA, capacityB);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
