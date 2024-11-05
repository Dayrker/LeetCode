/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int nums_len = nums.size();
        if (nums_len == 0) {    return 0;   }
        vector<int> dp(nums_len, 0);

        int maxL = 0;
        for (int i = 0; i < nums_len; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxL = max(maxL, dp[i]);
        }

        return maxL;
    }
};
// @lc code=end

