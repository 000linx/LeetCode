#include<iostream>
#include<vector>
/*二叉树中序遍历*/
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    void inorder(TreeNode *root,std::vector<int> &v)
    {
        if(root == nullptr)return ;
        //如果不为空就继续遍历左子树
        inorder(root->left,v);
        //为空就输出值
        v.push_back(root->val);
        //值输出后，再遍历右子树
        inorder(root->right,v);
    }
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int>v;
        inorder(root,v);
        return v;
    }
};