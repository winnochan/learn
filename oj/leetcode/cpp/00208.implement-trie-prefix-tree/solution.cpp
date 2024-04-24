// Created by WinnoChan at 2024/04/24 11:48
// leetgo: 1.4.5
// https://leetcode.cn/problems/implement-trie-prefix-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

struct Node {
    int pass, end;
    unordered_map<char, Node*> road;
    Node() {
        pass = 0;
        end = 0;
    }
    ~Node() {
        for (const auto& pair : road) {
            delete pair.second;
        }
    }
};

class Trie {
public:
    Trie() { root = new Node(); }
    ~Trie() { delete root; }

    void insert(const string& word) {
        root->pass++;
        Node* node = root;
        for (const auto ch : word) {
            if (!node->road.count(ch)) {
                node->road[ch] = new Node();
            }
            node = node->road[ch];
            node->pass++;
        }
        node->end++;
    }

    bool search(const string& word) {
        Node* node = root;
        for (const auto ch : word) {
            if (!node->road.count(ch)) {
                return false;
            }
            node = node->road[ch];
        }
        return node->end > 0;
    }

    bool startsWith(const string& prefix) {
        Node* node = root;
        for (const auto ch : prefix) {
            if (!node->road.count(ch)) {
                return false;
            }
            node = node->road[ch];
        }
        return node->pass > 0;
    }

private:
    Node* root = new Node();
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<string> method_names;
  LeetCodeIO::scan(cin, method_names);

  Trie *obj;
  const unordered_map<string, function<void()>> methods = {
    { "Trie", [&]() {
      cin.ignore();
      obj = new Trie();
      out_stream << "null,";
    } },
    { "insert", [&]() {
      string word; LeetCodeIO::scan(cin, word); cin.ignore();
      obj->insert(word);
      out_stream << "null,";
    } },
    { "search", [&]() {
      string word; LeetCodeIO::scan(cin, word); cin.ignore();
      LeetCodeIO::print(out_stream, obj->search(word)); out_stream << ',';
    } },
    { "startsWith", [&]() {
      string prefix; LeetCodeIO::scan(cin, prefix); cin.ignore();
      LeetCodeIO::print(out_stream, obj->startsWith(prefix)); out_stream << ',';
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
