/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */
#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0)); // 利用vector的构造函数(i, j)，构造i个全为j的数组
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) { dp[i][0] = dp[i - 1][0] + grid[i][0]; }
        for (int j = 1; j < n; j++) { dp[0][j] = dp[0][j - 1] + grid[0][j]; }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = min(dp[i-1][j] + grid[i][j], dp[i][j-1] + grid[i][j]);
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end

