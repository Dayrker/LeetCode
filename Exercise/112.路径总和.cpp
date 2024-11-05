/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return getPathSum(root, 0, targetSum);
    }

    bool getPathSum(TreeNode* node, int sum, int tar) {
        if (node == nullptr) {
            return false;
        }
        sum += node->val;
        if (node->left == nullptr && node->right == nullptr) {
            return sum == tar;
        }
        return getPathSum(node->left, sum, tar) || getPathSum(node->right, sum, tar);
    }
};
// @lc code=end

