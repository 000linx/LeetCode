#include <iostream>
#include <functional>

/*二叉树 + DFS*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){};
};

class Solution
{
public:
    bool isCousins(TreeNode *root, int x, int y)
    {
        int depth = 0;
        TreeNode *father = nullptr;
        std::function<bool(TreeNode *, TreeNode *, int)> dfs = [&](TreeNode *node, TreeNode *f, int deep) -> bool {
            if(node == nullptr)
            {
                return false;
            }
            if(node->val == x || node->val == y){
                if(depth){
                    return depth == deep && father != f;
                }
                depth = deep;
                father = f;
            }
            return dfs(node->left, node, deep + 1) || dfs(node->right, node, deep + 1);
        };
        return dfs(root, nullptr, 1);
    }
};