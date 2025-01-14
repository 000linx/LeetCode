#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
/*二叉树 + DFS*/
struct TreeNode
{
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
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        int ans = 0;
        std::function<void(TreeNode *)> dfs = [&](TreeNode *node) {
            if(node == nullptr){
                return;
            }
            if(node->val >= low && node->val <= high){
                ans += node->val;
            }
            dfs(node->left);
            dfs(node->right);
        };
        dfs(root);
        return ans;
    }
};