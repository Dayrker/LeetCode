/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int N = nums.size();
        int out = 0;
        for (int i = 0; i < N; i++) {   // 找出小于等于0的，不用考虑他
            if (nums[i] <= 0) {
                nums[i] = N + 1;
            }
        }
        for (int i = 0 ; i < N; i++) {
            int num_i = abs(nums[i]);
            if (num_i > 0 && num_i <= N && nums[num_i - 1] > 0) {
                nums[num_i - 1] = -nums[num_i - 1];
            }
        }
        for (int i = 0; i < N; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        return N + 1;
    }
};

// @lc code=end

