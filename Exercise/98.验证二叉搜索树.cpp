/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <limits.h>

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
    bool isValidBST(TreeNode* root) {
        return isBST(root->right, root->val, LONG_MAX) && isBST(root->left, LONG_MIN, root->val);    // fromLR: 0: from left, 1: from right
    }

    bool isBST(TreeNode* root, long l, long r) {
        if (root == nullptr) { return true; }

        if (root->val <= l || root->val >= r) {
            return false;
        }

        return isBST(root->right, root->val, r) && isBST(root->left, l, root->val);
    }
};
// @lc code=end

