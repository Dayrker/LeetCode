/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */
#include <string>
#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows < 2) {
            return s;
        }

        vector<string> outs = vector<string>(numRows);
        int flag = -1;
        int i = 0;
        for (char c : s) {
            // cout << i << " ";
            outs[i].push_back(c);
            if (i == 0 || i == numRows - 1) {
                flag = -flag;
            }
            i += flag;
        }

        string out;
        for (string s : outs) { out.append(s);  }
        return out;
    }
};
// @lc code=end

