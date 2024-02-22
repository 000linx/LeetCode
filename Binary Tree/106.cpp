#include <iostream>
#include <vector>
#include <functional>
#include <unordered_map>

/*中序后序构建二叉树*/

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
    TreeNode *buildTree(std::vector<int> &inorder, std::vector<int> &postorder)
    {
        int n = postorder.size();
        std::unordered_map<int, int> m(n);
        for (int i = 0; i < n; i++)
        {
            m[inorder[i]] = i;
        }

        std::function<TreeNode *(int, int, int, int)> dfs = [&](int il, int ir, int pos_l, int pos_r) -> TreeNode *
        {
            if (pos_l == pos_r)
            {
                return nullptr;
            }

            int left_size = m[postorder[pos_r - 1]] - il;
            TreeNode *left = dfs(il, il + left_size, pos_l, pos_l + left_size);
            TreeNode *right = dfs(il + left_size + 1, ir, pos_l + left_size, pos_r - 1);
            return new TreeNode(postorder[pos_r - 1], left, right);
        };

        return dfs(0, n, 0, n);
    }
};