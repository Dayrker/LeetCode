/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    int maxPS = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        int _ = GetMPS(root);
        return maxPS;
    }

    int GetMPS(TreeNode* node)
    {
        if (node == nullptr) {
            return 0;
        }
        int lM, rM;
        lM = max(GetMPS(node->left), 0);
        rM =  max(GetMPS(node->right), 0);

        maxPS = max(maxPS, node->val + lM + rM);
        return node->val + max(lM, rM);
    }
};
// @lc code=end

