/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */
#include <string>
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int s_len = 0;

    string getRepeatString(string& str, int& index) {
        string o;
        while (index < s_len && str[index] != ']') {
            char c = str[index];
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                o += c;
                index++;
            } else {
                int numRe = (int)(str[index++] - '0');
                while (index < s_len && str[index] != '[') {
                    numRe = 10 * numRe + (int)(str[index] - '0');
                    index++;
                }

                string temp = getRepeatString(str, ++index);
                for (int i = 0; i < numRe; i++) {
                    o += temp;
                }
            }
            // index++;
        }
        index++;
        return o;
    }

    string decodeString(string s) {
        s_len = s.length();
        string out;
        int index = 0;
        while (index < s.length()) {
            char c = s[index];
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                out += c;
            } else {
                out += getRepeatString(s, index);
            }
            index++;
        }

        return out;
    }
};
// @lc code=end

