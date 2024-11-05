/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// @lc code=start
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 0) return {};
		vector<int> res;
		deque<int> window;
		/*Init K integers in the list*/
		for (size_t i = 0; i < k; i++) {
			while (!window.empty() && nums[i] > nums[window.back()]) {
				window.pop_back();
			}
			window.push_back(i);
		}
		res.push_back(nums[window.front()]);
		/*End of initialization*/
		for (size_t i = k; i < nums.size(); i++) {
			if (!window.empty() && window.front() <= i - k) {
				window.pop_front();
			}
			while (!window.empty() && nums[i] > nums[window.back()]) {
				window.pop_back();
			}
			window.push_back(i);
			res.push_back(nums[window.front()]);
		}
		return res;
	}
};

// @lc code=end

