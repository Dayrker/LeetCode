/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        int number = 0, fuhao = 1;
        bool haveSeenFuhao = false, haveSeenNum = false;
        for (char num : s) {
            if (num == ' ') {
                if (haveSeenFuhao) {
                    break;
                }
                continue;
            } else if (num == '-') {
                if (haveSeenFuhao && !haveSeenNum) {
                    return 0;
                } else if (haveSeenFuhao) {
                    break;
                }
                fuhao = -1;
                haveSeenFuhao = true;
            } else if (num == '+') {
                if (haveSeenFuhao && !haveSeenNum) {
                    return 0;
                } else if (haveSeenFuhao) {
                    break;
                }
                fuhao = 1;
                haveSeenFuhao = true;
            } else if (num - '0' <= 9 && num - '0' >= 0) {
                haveSeenFuhao = true;
                haveSeenNum = true;
                if (fuhao > 0 && (number > INT_MAX / 10 || 10 * number > INT_MAX - int(num - '0'))) {
                    return INT_MAX;
                } else if (fuhao < 0 && (number < INT_MIN / 10 || 10 * number < INT_MIN + int(num - '0'))) {
                    return INT_MIN;
                } else {
                    number = 10 * number + fuhao * int(num - '0');
                }
            } else {
                break;
            }
        }
        return number;
    }
};
// @lc code=end

