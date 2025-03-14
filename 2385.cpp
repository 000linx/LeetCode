#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>
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
    int amountOfTime(TreeNode *root, int start)
    {
        std::unordered_map<int, std::vector<int>> graph;
        std::function<void(TreeNode *)> dfs = [&](TreeNode *node)
        {
            for (TreeNode *child : std::vector<TreeNode *>{node->left, node->right})
            {
                if (child != nullptr)
                {
                    graph[node->val].push_back(child->val);
                    graph[child->val].push_back(node->val);
                    dfs(child);
                }
            }
        };
        dfs(root);
        std::queue<std::vector<int>> q;
        q.push({start, 0});
        std::unordered_set<int> visited;
        visited.insert(start);
        int time = 0;
        while (!q.empty())
        {
            auto arr = q.front();
            q.pop();
            int nodeVal = arr[0];
            time = arr[1];
            for (int childVal : graph[nodeVal])
            {
                if (!visited.count(childVal))
                {
                    q.push({childVal, time + 1});
                    visited.insert(childVal);
                }
            }
        }
        return time;
    }
};