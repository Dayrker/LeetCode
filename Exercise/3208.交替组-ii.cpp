/*
 * @lc app=leetcode.cn id=3208 lang=cpp
 *
 * [3208] 交替组 II
 */
#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ExCount = 0;
        int Len = colors.size();

        // Count Exs
        int ExNums = 1;
        int index_m1 = 0;
        for (int i = 1; i < Len; i++) {
            index_m1 = (Len + i - 1) % Len;
            if (colors[i] != colors[index_m1])
                ExNums = min(ExNums + 1, k);
            else
                ExNums = 1;
            
            // cout << ExNums << endl;
            if (ExNums == k) ExCount += 1;
        }
        for (int i = 0; i < k - 1; i++) { // 做两遍，因为是个圈，可以前边连上后边
            index_m1 = (Len + i - 1) % Len;
            if (colors[i] != colors[index_m1])
                ExNums = min(ExNums + 1, k);
            else
                ExNums = 1;

            // cout << ExNums << endl;
            if (ExNums == k) ExCount += 1;
        }

        return ExCount;
    }
};
// @lc code=end

