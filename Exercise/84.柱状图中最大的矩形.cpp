/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        unsigned long size = heights.size();
        if (size == 1) {
            return heights[0];
        }
        int res = 0;
        stack<int> stk;

        for (int i = 0; i < size; ++i) {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                int length = heights[stk.top()];    // 遇到小于栈顶时，取出栈顶
                stk.pop();                      

                int weight = i;
                if (!stk.empty()) {
                    weight = i - stk.top() - 1;
                }
                res = max(res, length * weight);
            }
            stk.push(i);
        }
        while (!stk.empty()) {  // 到右边后，去除栈中剩余的值
            int length = heights[stk.top()];
            stk.pop();

            int weight = size;
            if (!stk.empty()) {
                weight = size - stk.top() - 1;
            }
            res = max(res, length * weight);
        }
        return res;
    }
};

// @lc code=end

