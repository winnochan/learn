// Created by WinnoChan at 2024/06/06 00:37
// leetgo: 1.4.7
// https://leetcode.cn/problems/distribute-elements-into-two-arrays-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class IndexTree {
public:
    IndexTree(int id) {
        maxId = id;
        ids.resize(maxId + 1, 0);
    }

    inline int sumOfPrefix(int i) {
        int ans = 0;
        while (i > 0) {
            ans += ids[i];
            i -= i & -i;
        }
        return ans;
    }

    inline int sumOfRange(int l, int r) {
        return sumOfPrefix(r) - sumOfPrefix(l - 1);
    }

    inline void add(int i, int v) {
        while (i <= maxId) {
            ids[i] += v;
            i += i & -i;
        }
    }

private:
    int maxId{0};
    vector<int> ids{};
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        unordered_set<int> numSet{};
        for (const auto n: nums) {
            numSet.insert(n);
        }

        int i = 0;
        int maxn = nums.size();
        int maxId = numSet.size();

        vector<int> uniqueNums(numSet.size(), 0);
        for (const auto n: numSet) {
            uniqueNums[i++] = n;
        }
        sort(uniqueNums.begin(), uniqueNums.end());

        unordered_map<int, int> idMap(maxId);
        for (i = 0; i < maxId; i++) {
            idMap[uniqueNums[i]] = i + 1;
        }

        vector<int> arr1{nums[0]};
        arr1.reserve(maxn);
        vector<int> arr2{nums[1]};
        arr2.reserve(maxn);

        IndexTree it1(maxId);
        IndexTree it2(maxId);

        it1.add(idMap[nums[0]], 1);
        it2.add(idMap[nums[1]], 1);

        for (i = 2; i < maxn; i++) {
            int val = nums[i];
            int vid = idMap[nums[i]];
            int sz1 = arr1.size();
            int sz2 = arr2.size();
            int gc1 = sz1 - it1.sumOfPrefix(vid);
            int gc2 = sz2 - it2.sumOfPrefix(vid);
            if (gc1 > gc2) {
                arr1.emplace_back(val);
                it1.add(vid, 1);
            } else if (gc1 < gc2) {
                arr2.emplace_back(val);
                it2.add(vid, 1);
            } else if (sz1 < sz2) {
                arr1.emplace_back(val);
                it1.add(vid, 1);
            } else if (sz1 > sz2) {
                arr2.emplace_back(val);
                it2.add(vid, 1);
            } else {
                arr1.emplace_back(val);
                it1.add(vid, 1);
            }
        }

        for (const auto n: arr2) {
            arr1.emplace_back(n);
        }
        return arr1;
    }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<int> nums;
  LeetCodeIO::scan(cin, nums);

  Solution *obj = new Solution();
  auto res = obj->resultArray(nums);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
