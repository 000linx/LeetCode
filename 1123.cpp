#include<iostream>
#include<vector>
#include<math.h>

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
    void pre(TreeNode *root,std::vector<int> &v){
        if(root == nullptr)return;
        v.push_back(root->val);
        pre(root->left,v);
        pre(root->right, v);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        std::vector<int>ans;
        pre(root,ans);
        
    }
};