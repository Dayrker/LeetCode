#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void buildTree(TreeNode* n, vector<int> & i, int index)
{
    if (index == i.size() || (index > 0 && i[index] > i[index - 1])) {
        return;
    }

    n = new TreeNode(i[index++]);
    buildTree(n->left, i, index);
    if (index == i.size() || (index > 0 && i[index] > i[index - 1])) {
        return;
    }
    buildTree(n->right, i, index);
}

void findLeafs(TreeNode* n, vector<int> & o)
{
    if (n->left == nullptr && n->right == nullptr) {
        o.emplace_back(n->val);
        return;
    }

    findLeafs(n->left, o);
    findLeafs(n->right, o);
}

int main()
{
    vector<int> input_;
    int temp;
    while (cin >> temp) {
        input_.emplace_back(temp);
        if (cin.get() == '\n') break;
    }

    TreeNode* root = new TreeNode();
    TreeNode* node = root;
    buildTree(node, input_, 0);

    vector<int> output_;
    findLeafs(root, output_);
    for (int i = 0; i < output_.size(); i++) {
        cout << output_[i] << ' ';
    }
    cout << endl;
    
    return 0;
}

