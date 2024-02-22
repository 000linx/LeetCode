#include <iostream>
#include <vector>
#include <functional>
#include <queue>

/*n叉树前序遍历*/

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
    std::vector<int> preorder(Node *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        std::vector<int> ans;
        std::function<void(Node *, std::vector<int>&)> dfs = [&](Node *node, std::vector<int> &v) -> void
        {
            if (node == nullptr)
            {
                return;
            }
            v.emplace_back(node->val);
            for(auto &ch: node->children){
                dfs(ch, v);
            }
        };
        dfs(root, ans);
        return ans;
    }
};