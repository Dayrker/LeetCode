/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */
#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        // G(n) = sum(i) G(i - 1) * G(n - i);
        vector<int> G(n + 1, 0);
        G[0] = G[1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                G[i] += G[j - 1] * G[i - j];
            }
        }

        return G[n];
    }
};
// @lc code=end

