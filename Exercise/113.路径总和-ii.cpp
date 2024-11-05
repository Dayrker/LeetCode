/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
#include <vector>
using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
    vector<vector<int>> paths;
    vector<int> path;
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        getPathSum(root, 0, targetSum);
        return paths;
    }

    void getPathSum(TreeNode* node, int sum, int tar) {
        if (node == nullptr) {
            return;
        }
        path.emplace_back(node->val);
        sum += node->val;
        if (node->left == nullptr && node->right == nullptr) {
            if (sum == tar) {
                paths.emplace_back(path);
            }
        }
        getPathSum(node->left, sum, tar);
        getPathSum(node->right, sum, tar);
        path.pop_back();
    }
};
// @lc code=end

