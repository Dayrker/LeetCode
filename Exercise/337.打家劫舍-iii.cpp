/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 */
#include <vector>
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

vector<int> getMoneys(TreeNode* root) {
    if (root == nullptr) {  return vector<int>{0, 0};   }
    if (root->left == nullptr && root->right == nullptr) {
        return vector<int>{0, root->val};
    }

    vector<int> l = getMoneys(root->left);
    vector<int> r = getMoneys(root->right);
    // [0]代表没拿，[1]代表拿了
    return vector<int>{max(l[0], l[1]) + max(r[0], r[1]), l[0] + r[0] + root->val};
}

class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> moneys = getMoneys(root);
        return max(moneys[0], moneys[1]);
    }
};
// @lc code=end

