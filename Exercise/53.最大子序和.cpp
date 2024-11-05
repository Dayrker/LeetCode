/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int nums_len = nums.size();
        int maxS = nums[0];

        int maxS_temp = nums[0];
        for (int i = 1; i < nums_len; i++) {
            maxS_temp = max(nums[i], maxS_temp + nums[i]);
            maxS = max(maxS, maxS_temp);
        }
        return maxS;
    }
};
// @lc code=end

