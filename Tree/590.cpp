#include <iostream>
#include <vector>
#include <functional>
#include <queue>

/*n叉树后序遍历*/

class Node
{
public:
    int val;
    std::vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, std::vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    std::vector<int> postorder(Node *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        std::vector<int> ans;
        std::function<void(Node *, std::vector<int> &)> dfs = [&](Node *node, std::vector<int> &v) -> void
        {
            if (node == nullptr)
            {
                return;
            }
            for (auto &ch : node->children)
            {
                dfs(ch, v);
            }
            v.emplace_back(node->val);
        };
        dfs(root, ans);
        return ans;
    }
};