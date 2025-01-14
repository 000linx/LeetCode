#include <iostream>
#include <vector>
#include <functional>
#include <unordered_map>

/*前序中序构建二叉树*/

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
    TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder)
    {
        int n = preorder.size();
        std::unordered_map<int, int> m(n);
        for (int i = 0; i < n; i++)
        {
            m[inorder[i]] = i;
        }

        std::function<TreeNode *(int, int, int, int)> dfs = [&](int pl, int pr, int il, int ir) -> TreeNode *
        {
            if (pl == pr)
            {
                return nullptr;
            }
            int l_size = m[preorder[pl]] - il;
            TreeNode *left = dfs(pl + 1, pl + 1 + l_size, il, il + l_size);
            TreeNode *right = dfs(pr + 1 + l_size, pr, il + 1 + l_size, ir);
            return new TreeNode(preorder[pl], left, right);
        };
        return dfs(0, n, 0, n);
    }
};