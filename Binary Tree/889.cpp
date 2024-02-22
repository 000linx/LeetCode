#include <iostream>
#include <vector>
#include <functional>
#include <unordered_map>

/*前后序构建二叉树*/

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
    TreeNode *constructFromPrePost(std::vector<int> &preorder, std::vector<int> &postorder)
    {
        int n = preorder.size();
        std::unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[postorder[i]] = i;
        }

        std::function<TreeNode *(int, int, int, int)> dfs = [&](int pr_l, int pr_r, int pos_l, int pos_r) -> TreeNode *
        {
            if (pr_l > pr_r)
            {
                return nullptr;
            }
            int left_size = 0;
            if (pr_l < pr_r)
            {
                left_size = m[preorder[pr_l + 1]] - pos_l + 1;
            }
            TreeNode *left = dfs(pr_l + 1, pr_l + left_size, pos_l, pos_l + left_size - 1);
            TreeNode *right = dfs(pr_l + left_size + 1, pr_r, pos_l + left_size, pos_r - 1);
            return new TreeNode(preorder[pr_l], left, right);
        };
        return dfs(0, n - 1, 0, n - 1);
    }
};