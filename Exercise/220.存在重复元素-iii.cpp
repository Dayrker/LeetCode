/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */
#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
    int getID(int num, long w) {
        return num < 0 ? (num + 1ll) / w - 1 : num / w;
    }
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        unordered_map<int, int> tons;
        int nums_len = nums.size();
        for (int i = 0; i < nums_len; i++) {
            long x = nums[i];
            int id = getID(x, t + 1ll);
            if (tons.count(id)) {
                return true;
            } else if (tons.count(id - 1) && abs(x - tons[id - 1]) <= t) {
                return true;
            } else if (tons.count(id + 1) && abs(x - tons[id + 1]) <= t) {
                return true;
            }
            tons[id] = x;
            if (i >= k) {
                tons.erase(getID(nums[i - k], t + 1ll));
            }
        }

        return false;
    }
};
// @lc code=end

