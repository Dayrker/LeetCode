/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return;
        }

        int i;
        for (i = n - 1; i > 0; i--) {
            if (nums[i] > nums[i-1]) { // 此时i后面都是倒序，下一个字典序即将最小的大于i-1的换上来
                int j;
                for (j = n - 1; j > i; j--) {
                    if (nums[j] > nums[i-1]) {
                        break;
                    }
                }

                int temp = nums[j];
                nums[j] = nums[i-1];
                nums[i-1] = temp;
                break;
            }
        }
        reverse(nums.begin() + i, nums.end());
        return;
    }
};
// @lc code=end

