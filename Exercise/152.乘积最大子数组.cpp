/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxF, minF;
        int maxP;
        maxF = minF = maxP = nums[0];
        int premaxF;
        for (int i = 1; i < nums.size(); ++i) {
            premaxF = maxF;
            maxF = max(maxF * nums[i], max(nums[i], minF * nums[i]));
            minF = min(minF * nums[i], min(nums[i], premaxF * nums[i]));
            maxP = max(maxP, maxF);
        }

        return maxP;
    }
};

// @lc code=end

