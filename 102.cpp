#include <iostream>
#include <vector>
#include <queue>

/*二叉树 + BFS*/

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
    std::vector<std::vector<int>> levelOrder(TreeNode *root)
    {
        std::vector<std::vector<int>> ans;
        std::queue<TreeNode *> q;
        if (root == nullptr)
            return {};
        q.push(root);
        while (!q.empty())
        {
            std::vector<int> v;
            for (int i = q.size(); i--;)
            {
                auto T = q.front();
                q.pop();
                v.push_back(T->val);
                if (T->left)
                    q.push(T->left);
                if (T->right)
                    q.push(T->right);
            }
            ans.emplace_back(v);
        }
        return ans;
    }
};
