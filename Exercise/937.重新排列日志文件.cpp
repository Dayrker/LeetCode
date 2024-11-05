/*
 * @lc app=leetcode.cn id=937 lang=cpp
 *
 * [937] 重新排列日志文件
 */
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        // 首先分开字母和数字
        vector<string> logsZimu, logsShuzi = vector<string>();
        for (string s : logs) {
            int find_ = s.find(" ");
            if (find_ != -1) {
                if (s[find_+1] >= 'a' && s[find_+1] <= 'z') {
                    logsZimu.push_back(s);
                    // cout << s << endl;
                } else {
                    logsShuzi.push_back(s);
                }
            }
        }

        sort(logsZimu.begin(), logsZimu.end(), [](const string& str1, const string& str2) {
            string substr1 = str1.substr(str1.find(' ') + 1);
            string substr2 = str2.substr(str2.find(' ') + 1);
            return (substr1 == substr2) ? str1 < str2 : substr1 < substr2;
        });
        logs.clear();
        for (string s : logsZimu) { logs.push_back(s);  }
        for (string s : logsShuzi) { logs.push_back(s);  }

        return logs;
    }
};
// @lc code=end

