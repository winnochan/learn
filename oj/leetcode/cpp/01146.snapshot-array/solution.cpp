// Created by WinnoChan at 2024/04/26 02:01
// leetgo: 1.4.5
// https://leetcode.cn/problems/snapshot-array/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

struct Node {
    int sid, val;
    Node(int sid, int val) : sid(sid), val(val) {}
};

class SnapshotArray {
public:
    SnapshotArray(int length) { vec.resize(length); }

    void set(int index, int val) {
        vector<Node>& sarr = vec[index];
        int n = sarr.size();
        if (!n) {
            sarr.emplace_back(Node(sid, val));
        } else {
            auto& last = sarr[n - 1];
            if (last.sid == sid) {
                last.val = val;
            } else {
                sarr.emplace_back(Node(sid, val));
            }
        }
    }

    int snap() { return sid++; }

    int get(int index, int snap_id) {
        vector<Node>& sarr = vec[index];
        int n = sarr.size();
        if (!n)
            return 0;

        int l = 0;
        int r = n - 1;
        int m;
        while (l <= r) {
            m = l + ((r - l) >> 1);
            if (sarr[m].sid > snap_id) {
                // [l, r] 闭区间的最大值 <= snap_id
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        if (r < 0) return 0;
        return sarr[r].val;
    }

    void printVec(int index, int snap_id, vector<Node>& vec) {
        printf("(%d,%d) ", index, snap_id);
        for (const auto& val: vec) {
            printf("(sid=%d,val=%d) ", val.sid, val.val);
        }
        cout << '\n';
    }

    void printInfo() {
        int i = 0;
        for (const auto& vals : vec) {
            cout << i++ << ": ";
            for (const auto& v : vals) {
                printf("(%d,%d) ", v.sid, v.val);
            }
            cout << '\n';
        }
        cout << "=========================\n";
    }

private:
    int sid = 0;
    vector<vector<Node>> vec;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<string> method_names;
  LeetCodeIO::scan(cin, method_names);

  SnapshotArray *obj;
  const unordered_map<string, function<void()>> methods = {
    { "SnapshotArray", [&]() {
      int length; LeetCodeIO::scan(cin, length); cin.ignore();
      obj = new SnapshotArray(length);
      out_stream << "null,";
    } },
    { "set", [&]() {
      int index; LeetCodeIO::scan(cin, index); cin.ignore();
      int val; LeetCodeIO::scan(cin, val); cin.ignore();
      obj->set(index, val);
      out_stream << "null,";
    } },
    { "snap", [&]() {
      cin.ignore();
      LeetCodeIO::print(out_stream, obj->snap()); out_stream << ',';
    } },
    { "get", [&]() {
      int index; LeetCodeIO::scan(cin, index); cin.ignore();
      int snap_id; LeetCodeIO::scan(cin, snap_id); cin.ignore();
      LeetCodeIO::print(out_stream, obj->get(index, snap_id)); out_stream << ',';
    } },
  };
  cin >> ws;
  out_stream << '[';
  for (auto &&method_name : method_names) {
    cin.ignore(2);
    methods.at(method_name)();
  }
  cin.ignore();
  out_stream.seekp(-1, ios_base::end); out_stream << ']';
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
