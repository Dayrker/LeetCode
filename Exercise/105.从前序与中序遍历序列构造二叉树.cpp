/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */
#include <vector>
#include <unordered_map>
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
    unordered_map<int, int> num2index;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            num2index[inorder[i]] = i;
        }
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* buildTree(vector<int>& pres, int p_start, int p_end, vector<int>& ins, int i_start, int i_end)
    {
        if (p_start > p_end) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(pres[p_start]);

        // 查找pres[p_start]即root在ins中的位置
        int rootInins = num2index[pres[p_start]];

        // rootInins左边的中序，和p_start后边相同数量的数字，可作为左子树需要的俩数组递归构造
        int leftNum = rootInins - i_start;
        root->left = buildTree(pres, p_start + 1, p_start + leftNum, ins, i_start, rootInins - 1);
        root->right = buildTree(pres, p_start + leftNum + 1, p_end, ins, rootInins + 1, i_end);
        return root;
    }
};
// @lc code=end

