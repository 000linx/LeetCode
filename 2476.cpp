#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
/*二叉树 + 二分查找*/
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
    std::vector<std::vector<int>> closestNodes(TreeNode *root, std::vector<int> &queries)
    {
        std::vector<std::vector<int>> ans;
        if (root == nullptr)
        {
            return {};
        }
        std::queue<TreeNode *> q;
        std::vector<int> v;
        q.push(root);

        while (!q.empty())
        {
            for (int i = q.size(); i--;)
            {
                auto node = q.front();
                q.pop();
                v.push_back(node->val);
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
        }

        sort(v.begin(), v.end());
        int n = v.size();
        for (int val : queries)
        {
            int it = std::lower_bound(v.begin(), v.end(), val) - v.begin();
            int Max = it < n ? v[it] : -1;
            if (it == n || v[it] != val)
            {
                it--;
            }
            int Min = it >= 0 ? v[it] : -1;
            ans.push_back({Min, Max});
        }
        return ans;
    }
};