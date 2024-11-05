/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
#include <vector>
#include <iostream>
using namespace std;


// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> out;
        sort(intervals.begin(), intervals.end());

        vector<int> sec = intervals[0];
        int l_pre = sec[0];
        int r_pre = sec[1];
        for (int i = 1; i < intervals.size(); i++) {
            if (r_pre >= intervals[i][0]) {
                if (r_pre < intervals[i][1]) {
                    sec[1] = intervals[i][1];
                    r_pre = sec[1];
                } else {
                    continue;
                }
            } else {
                out.emplace_back(sec);
                sec = intervals[i];
                l_pre = sec[0];
                r_pre = sec[1];
            }
        }

        out.emplace_back(sec);
        return out;
    }
};
// @lc code=end

