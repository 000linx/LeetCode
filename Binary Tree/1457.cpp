#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

/*二叉树 + DFS*/
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
    int ans;
    int dfs(TreeNode *root,int count){
        if(!root ->left && !root ->right){
            count ^= 1 <<  root->val;
            if(count == (count & -count))
                ans++;
            return;
        }
        if(root -> left)
            dfs(root->left, count ^ (1 << root->val));
        if(root -> right)
            dfs(root->right, count ^ (1 << root->val));
    }
    int pseudoPalindromicPaths(TreeNode *root)
    {
        dfs(root, 0);
        return ans;
    }
};