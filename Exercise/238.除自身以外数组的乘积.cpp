/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> preMuls, lastMuls;
        int nums_len = nums.size();
        preMuls.emplace_back(nums[0]);
        lastMuls.emplace_back(nums[nums_len - 1]);
        for (int i = 1; i < nums_len - 1; i++) {
            preMuls.emplace_back(preMuls[i - 1] * nums[i]);
            lastMuls.emplace_back(lastMuls[i - 1] * nums[nums_len - 1 - i]);
        }

        vector<int> out;
        out.emplace_back(lastMuls[nums_len - 2]);
        for (int i = 1; i < nums_len - 1; i++) {
            out.emplace_back(preMuls[i - 1] * lastMuls[nums_len - 2 - i]);
        }
        out.emplace_back(preMuls[nums_len - 2]);
        return out;
    }
};
// @lc code=end

