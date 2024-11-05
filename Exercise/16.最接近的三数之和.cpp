/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
private:
    int best = 1e7;
    int tar = 0;

public:
    int threeSumClosest(vector<int>& nums, int target) {
        tar = target;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            // 使用双指针
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    return target;
                } else {
                    update_best(sum);
                }

                if (sum > target) {
                    int k_minus = k - 1;
                    while (j < k_minus && nums[k_minus] == nums[k]) {   // 去除重复nums[k]，走到下一个不同的值
                        k_minus--;
                    }
                    k = k_minus;
                } else {
                    int j_plus = j + 1;
                    while (j_plus < k && nums[j_plus] == nums[j]) {
                        j_plus++;
                    }
                    j = j_plus;
                }
            }
            
        }
        return best;
    }

    void update_best(int sum)
    {
        best = abs(sum - tar) < abs(best - tar) ? sum : best;
    }
};
// @lc code=end

