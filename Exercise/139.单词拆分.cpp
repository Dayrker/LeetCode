/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int s_len = s.length();
        vector<bool> dp(s_len + 1, false);
        int maxLw = 0;
        unordered_set<string> wordD;
        for (const string & s: wordDict) {
            wordD.insert(s);
            maxLw = max(maxLw, (int)s.length());
        }

        dp[0] = true;
        for (int i = 1; i <= s_len; i++) {
            for (int j = i - 1; j >= 0 && j >= i - maxLw; j--) {   // 在这一步逐个j拆分判断0-i的字串，是否可拆分为wordDict里面的
                if (dp[j] && wordD.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s_len];
    }
};
// @lc code=end

