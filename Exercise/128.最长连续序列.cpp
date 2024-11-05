/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */
#include <vector>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (int num: nums) {
            num_set.insert(num);
        }

        int L = 0, tempL = 0;
        for (const int & num: num_set) {
            if (num_set.count(num - 1) > 0) { continue; }

            int curNum = num;
            tempL = 0;
            while (num_set.count(curNum++) > 0) {
                tempL++;
            }
            L = max(tempL, L);
        }
        return L;
    }
};
// @lc code=end

