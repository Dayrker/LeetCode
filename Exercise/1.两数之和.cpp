/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;

        int index = 0;
        int sub_num = 0;
        for (index = 0; index < nums.size(); index++) {
            sub_num = target - nums[index];
            if (hashtable.find(sub_num) != hashtable.end()) {
                return {hashtable[sub_num], index};
            } else {
                hashtable[nums[index]] = index;
            }
        }
        return {};
    }
};
// @lc code=end

