/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */
#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        if (n == 1) { return dp[n - 1]; }
        dp[1] = 2;
        for (int i = 2; i < n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n - 1];
    }
};
// @lc code=end

