// Created by WinnoChan at 2024/04/21 07:00
// leetgo: 1.4.5
// https://leetcode.cn/problems/text-justification/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;

        int begin = 0;
        while (begin < words.size()) {
            int next = getNextIndex(words, begin, maxWidth);
            int cnt = 0;
            for (int i = begin; i < next; i++) {
                cnt += words[i].size();
            }
            int space = maxWidth - cnt;
            // printf("begin=%d,next=%d,cnt=%d,space=%d\n", begin, next, cnt, space);

            int len = next - begin;
            if (len == 1) {
                // 左对齐
                int spaceNum = (maxWidth - cnt);
                string gen = genSpace(spaceNum);
                ans.push_back(words[begin] + gen);
            } else if (next < words.size()) {
                int spaceCnt = len - 1;
                int spaceNum = (maxWidth - cnt) / spaceCnt;
                int spaceExt = maxWidth - cnt - spaceCnt * spaceNum;
                // printf("cnt=%d,num=%d,ext=%d\n", spaceCnt, spaceNum, spaceExt);

                string temp = words[begin];
                for (int i = 1; i <= spaceCnt; i++) {
                    if (i <= spaceExt) {
                        temp += genSpace(spaceNum + 1);
                    } else {
                        temp += genSpace(spaceNum);
                    }
                    temp += words[begin + i];
                }
                // cout << temp << endl;
                ans.push_back(temp);
            } else {
                string temp = words[begin];
                for (int i = 1; i < len; i++) {
                    temp += " " + words[begin + i];
                }
                temp += genSpace(maxWidth - temp.size());
                // cout << temp << endl;
                ans.push_back(temp);
            }

            begin = next;
        }

        return ans;
    }

    string genSpace(int n) {
        if (n <= 0) return "";
        if (n == 1) return " ";
        string temp  = genSpace(n / 2);
        if (n % 2) {
            return " " + temp + temp;
        } else {
            return temp + temp;
        }
    }

    int getNextIndex(vector<string>& words, int begin, int maxWidth) {
        int cnt = words[begin].size();
        while (cnt <= maxWidth && ++begin < words.size()) {
            cnt += 1 + words[begin].size();
        }
        return begin;
    }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  vector<string> words;
  LeetCodeIO::scan(cin, words);
  int maxWidth;
  LeetCodeIO::scan(cin, maxWidth);

  Solution *obj = new Solution();
  auto res = obj->fullJustify(words, maxWidth);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
