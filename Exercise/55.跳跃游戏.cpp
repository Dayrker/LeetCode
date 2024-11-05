/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
#include <vector>
#include <cmath>
using namespace std;


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int nums_len = nums.size();
        int max_right = 0;

        for (int i = 0; i < nums_len; i++) {
            if (i <= max_right) {
                max_right = max(max_right, i + nums[i]);
            }
            if (max_right >= nums_len - 1) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

