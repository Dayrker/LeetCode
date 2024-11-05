/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */
#include <vector>
#include <limits.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int minPre = INT_MAX;
            for (int j = 1; j * j <= i; j++) { // 若j=0，则相当于从自己dp[i]开始，这时候dp[i]还是0，无意义
                minPre = min(minPre, dp[i - j * j]);
            }
            dp[i] = minPre + 1;
        }
        return dp[n];
    }
};
// @lc code=end

