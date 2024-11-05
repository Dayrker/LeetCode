/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 */
#include <vector>
#include <iostream>
using namespace std;

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
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        TreeNode* temp = buildLink(root);
        *root = *temp;
        return;
    }

    TreeNode* buildLink(TreeNode* node)
    {
        if (node == nullptr) {
            return node;
        }

        // 获得展开的左边部分和右边部分
        TreeNode* nr = buildLink(node->right);
        node->right = buildLink(node->left);
        node->left = nullptr;

        // 拼接右边部分
        TreeNode* n = node;
        while (n->right != nullptr) {
            n = n->right;
        }
        n->right = nr;
        
        return node;
    }
};
// @lc code=end

