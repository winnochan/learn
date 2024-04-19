// Created by WinnoChan at 2024/04/20 02:39
// leetgo: 1.4.5
// https://leetcode.cn/problems/insert-delete-getrandom-o1/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class RandomizedSet {
public:
  RandomizedSet() {
    srand(static_cast<unsigned int>(time(NULL)));
    umap = unordered_map<int, int>();
    vec = vector<int>();
  }

  bool insert(int val) {
    if (umap.count(val)) return false;
    vec.push_back(val);
    umap[val] = vec.size() - 1;
    return true;
  }

  bool remove(int val) {
    if (!umap.count(val)) return false;
    auto index = umap[val];
    vec[index] = vec.back();
    umap[vec[index]] = index;

    vec.pop_back();
    umap.erase(val);
    return true;
  }

  int getRandom() {
    return vec[rand() % vec.size()];
  }

private:
  unordered_map<int, int> umap;
  vector<int> vec;
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<string> method_names;
  LeetCodeIO::scan(cin, method_names);

  RandomizedSet *obj;
  const unordered_map<string, function<void()>> methods = {
    { "RandomizedSet", [&]() {
      cin.ignore();
      obj = new RandomizedSet();
      out_stream << "null,";
    } },
    { "insert", [&]() {
      int val; LeetCodeIO::scan(cin, val); cin.ignore();
      LeetCodeIO::print(out_stream, obj->insert(val)); out_stream << ',';
    } },
    { "remove", [&]() {
      int val; LeetCodeIO::scan(cin, val); cin.ignore();
      LeetCodeIO::print(out_stream, obj->remove(val)); out_stream << ',';
    } },
    { "getRandom", [&]() {
      cin.ignore();
      LeetCodeIO::print(out_stream, obj->getRandom()); out_stream << ',';
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
