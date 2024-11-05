/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        for (int i = 0; i <= right; i++) {  // 向左换（左边都是排序好的）和遇到1都需要i++，但是向右换过来的数字就需要再考虑一下了
            if (nums[i] == 0) {
                exchange(nums, left++, i);
            } else if (nums[i] == 2) {
                exchange(nums, i, right--);
                i--;
            }
        }
    }

    void exchange(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};
// @lc code=end

