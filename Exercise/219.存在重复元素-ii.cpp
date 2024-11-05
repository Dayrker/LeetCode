/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */
#include <vector>
#include <unordered_map>
using namespace std;


// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> num2index;
        for (int i = 0; i < nums.size(); i++) {
            if (num2index.find(nums[i]) != num2index.end() && i - num2index[nums[i]] <= k) {
                return true;
            }
            num2index[nums[i]] = i;
        }
        return false;
    }
};
// @lc code=end

