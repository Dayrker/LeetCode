/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */
#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        int dp_lu;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i < m + 1; i++) {
            dp[i][0] = i;
        }
        for (int j = 1; j < n + 1; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                dp_lu = word1[i - 1] == word2[j - 1] ? dp[i-1][j-1] - 1 : dp[i-1][j-1];
                dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp_lu});
            }
        }

        return dp[m][n];
    }
};
// @lc code=end

