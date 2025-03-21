#include <iostream>
#include <vector>
/*二叉树递归*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){} 
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){} 
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}  
};

class Solution
{
public:
    int sum = 0;

    void dfs(TreeNode *node)
    {
        if (node == nullptr)
            return;
        dfs(node->right);
        sum += node->val;
        node->val = sum;
        dfs(node->left);
    }

    TreeNode *bstToGst(TreeNode *root)
    {
        dfs(root);
        return root;
    }
};