/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

// @lc code=start
class Solution {
    int nums_len;
    vector<int> ziji_tree;
    vector<vector<int>> zijis;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        nums_len = nums.size();
        Get_ziji(0, nums);
        return zijis;
    }

    void Get_ziji(int depth, vector<int> & nums)
    {
        if (depth >= nums_len) {
            zijis.emplace_back(ziji_tree);
            return;
        }

        ziji_tree.emplace_back(nums[depth]);
        Get_ziji(depth + 1, nums);
        ziji_tree.pop_back();
        Get_ziji(depth + 1, nums);
        return;
    }
};
// @lc code=end

