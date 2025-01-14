#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<unordered_map>
/*
根节点要不要偷
1.要偷根节点
总金额 = 根节点 + 子节点的子节点
2.不偷根节点
总金额 = 子节点
*/
 

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution
{
public:
    std::unordered_map<TreeNode *, int> f, g;
    void dfs(TreeNode *root)
    {
        if(root == nullptr)
            return;
        dfs(root->left);
        dfs(root->right);
        f[root] = root->val + g[root->left] + g[root->right];
        g[root] = std::max(f[root->left], g[root->left]) + std::max(f[root->right], g[root->right]);

    }
    int rob(TreeNode *root)
    {
        dfs(root);
        return std::max(f[root], g[root]);
    }
};