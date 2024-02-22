#include <iostream>
#include <vector>
#include <queue>

/*n叉树 + BFS*/

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
    std::vector<std::vector<int>> levelOrder(Node *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        std::vector<std::vector<int>> ans;
        std::queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            std::vector<int> v;
            for (int i = q.size(); i--;)
            {
                auto node = q.front();
                q.pop();
                v.push_back(node->val);
                for (auto c : node->children)
                {
                    q.push(c);
                }
            }
            ans.emplace_back(v);
        }
        return ans;
    }
};