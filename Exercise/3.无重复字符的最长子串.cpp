/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include <string>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) {
            return 0;
        }
        unordered_map<char, int> haveSeens;

        int left = 0;
        int maxL = 0;
        for (int r = 0; r < s.length(); r++) {
            if (haveSeens.find(s[r]) == haveSeens.end()) {
                maxL = max(maxL, r - left + 1);
            } else {
                char temp = s[r];
                left = max(haveSeens[temp] + 1, left);
                maxL = max(maxL, r - left + 1);
                haveSeens.erase(temp);
            }
            haveSeens[s[r]] = r;
        }

        return maxL;
    }
};
// @lc code=end

