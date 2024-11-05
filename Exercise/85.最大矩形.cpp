/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }
        int n = matrix[0].size();
        vector<int> heights(n, 0);
        int maxRec;

        // 为每一行设置好上方的矩阵高度图
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
            maxRec = max(maxRec, getMaxRec(heights));
        }
        return maxRec;
    }

    int getMaxRec(vector<int> hs) {
        int hs_len = hs.size();
        int maxR, h;
        stack<int> indexes;
        for (int i = 0; i < hs_len; i++) {
            while (!indexes.empty() && hs[indexes.top()] > hs[i]) {
                h = hs[indexes.top()];
                indexes.pop();

                int weight = i;
                if (!indexes.empty()) {
                    weight = i - indexes.top() - 1;
                }
                maxR = max(maxR, weight * h);
            }
            indexes.push(i);
        }
        while (!indexes.empty()) {
            h = hs[indexes.top()];
            indexes.pop();

            int weight = hs_len;
            if (!indexes.empty()) {
                weight = hs_len - indexes.top() - 1;
            }
            maxR = max(maxR, weight * h);
        }

        return maxR;
    }
};
// @lc code=end

