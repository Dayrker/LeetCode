/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */
#include <vector>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> nums_set;
        for (int num : nums) {
            nums_set.insert(num);
        }
        return nums_set.size() < nums.size();
    }
};
// @lc code=end

