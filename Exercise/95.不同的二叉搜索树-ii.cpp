/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 */
#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
/**
 * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 */
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }
        return getTrees(1, n);
    }

    vector<TreeNode*> getTrees(int start, int end)
    {
        if (start > end) {
            return {nullptr};
        }
        vector<TreeNode*> treesRoot;

        for (int i = start; i <= end; i++) {
            vector<TreeNode*> treesLeft = getTrees(start, i - 1);  // 寻找可能的左右子树
            vector<TreeNode*> treesRight = getTrees(i + 1, end);  // 寻找可能的左右子树

            for (auto & treeL : treesLeft) {
                for (auto & treeR : treesRight) {
                    treesRoot.emplace_back(new TreeNode(i, treeL, treeR));
                }
            }
        }
        return treesRoot;
    }
};
// @lc code=end

