/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>
using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };


class Solution {
    TreeNode* father;
public:
    bool findComAnc(TreeNode* node, TreeNode* pp, TreeNode* qq) {
        if (node == nullptr) {
            return false;
        }
        bool inL = findComAnc(node->left, pp, qq);
        bool inR = findComAnc(node->right, pp, qq);
        if ((inL && inR) || (node->val == pp->val || node->val == qq->val) && (inL || inR)) {
            father = node;
        }
        return inL || inR || (node->val == pp->val || node->val == qq->val);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        findComAnc(root, p, q);
        return father;
    }
};
// @lc code=end

