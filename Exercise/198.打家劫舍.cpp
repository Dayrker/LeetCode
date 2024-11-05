/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int nums_len = nums.size();
        if (nums_len <= 1) {
            return nums[0];
        }

        // dp[0]:拿之dp ; dp[1]:不拿之dp
        vector<vector<int>> dp(2, vector<int>(nums.size(), 0));
        dp[0][0] = nums[0];
        dp[0][1] = nums[1]; // 拿的
        dp[1][0] = 0;
        dp[1][1] = max(dp[0][0], dp[1][0]); // 这次不拿，最大值肯定是上一次拿or不拿之间最大值
        for (int i = 2; i < nums.size(); i++) { 
            dp[0][i] = dp[1][i - 1] + nums[i];
            dp[1][i] = max(dp[0][i - 1], dp[1][i - 1]);
        }
        return max(dp[0][nums_len - 1], dp[1][nums_len - 1]);
    }
};
// @lc code=end

