// Created by WinnoChan at 2024/04/17 02:57
// leetgo: 1.4.5
// https://leetcode.cn/problems/design-hashmap/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class MyHashMap {
public:
    MyHashMap() {

    }
    
    void put(int key, int value) {

    }
    
    int get(int key) {

    }
    
    void remove(int key) {

    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<string> method_names;
	LeetCodeIO::scan(cin, method_names);

	MyHashMap *obj;
	const unordered_map<string, function<void()>> methods = {
		{ "MyHashMap", [&]() {
			cin.ignore();
			obj = new MyHashMap();
			out_stream << "null,";
		} },
		{ "put", [&]() {
			int key; LeetCodeIO::scan(cin, key); cin.ignore();
			int value; LeetCodeIO::scan(cin, value); cin.ignore();
			obj->put(key, value);
			out_stream << "null,";
		} },
		{ "get", [&]() {
			int key; LeetCodeIO::scan(cin, key); cin.ignore();
			LeetCodeIO::print(out_stream, obj->get(key)); out_stream << ',';
		} },
		{ "remove", [&]() {
			int key; LeetCodeIO::scan(cin, key); cin.ignore();
			obj->remove(key);
			out_stream << "null,";
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
