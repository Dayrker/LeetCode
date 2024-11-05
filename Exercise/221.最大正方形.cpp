/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */
#include <vector>
#include <math.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m, n;
        m = matrix.size();
        n = matrix[0].size();
        if (m == 0 || n == 0) {
            return 0;
        }

        int maxL = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                    }
                    maxL = max(maxL, dp[i][j]);
                }
            }
        }
        return maxL * maxL;
    }
};
// @lc code=end

