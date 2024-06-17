// Created by WinnoChan at 2024/06/18 01:56
// leetgo: 1.4.7
// https://leetcode.cn/problems/apply-discount-to-prices/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    string discountPrices(string sentence, int discount) {
        stringstream ans{};

        double coe = (100 - discount) / 100.0;

        string temp{};
        stringstream ss(sentence);
        stringstream ts{};

        if (!getline(ss, temp, ' ')) {
            return ans.str();
        }
        if (isPrice(temp)) {
            double num = stod(temp.substr(1, temp.size() - 1)) * coe;
            ts << "$" << setprecision(2) << fixed << num;
            ans << ts.str();
        } else {
            ans << temp;
        }

        while (getline(ss, temp, ' ')) {
            ans << " ";
            if (isPrice(temp)) {
                double num = stod(temp.substr(1, temp.size() - 1)) * coe;
                ts.str("");
                ts << "$" << setprecision(2) << fixed << num;
                ans << ts.str();
            } else {
                ans << temp;
            }
        }
        return ans.str();
    }

    bool isPrice(string& str) {
        int n = str.size();
        if (n < 2 || str[0] != '$')
            return false;
        int dotNum = 0;
        for (int i = 1; i < n; i++) {
            if (!isdigit(str[i])) {
                if (str[i] != '.') {
                    return false;
                } else {
                    dotNum++;
                }
                if (dotNum >= 2) {
                    return false;
                }
            }
        }
        return true;
    }
};

// @lc code=end

int main() {
  ios_base::sync_with_stdio(false);
  stringstream out_stream;

  string sentence;
  LeetCodeIO::scan(cin, sentence);
  int discount;
  LeetCodeIO::scan(cin, discount);

  Solution *obj = new Solution();
  auto res = obj->discountPrices(sentence, discount);
  LeetCodeIO::print(out_stream, res);
  cout << "\noutput: " << out_stream.rdbuf() << endl;

  delete obj;
  return 0;
}
