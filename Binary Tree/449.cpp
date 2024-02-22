#include <iostream>
#include <string>
#include <vector>
#include <queue>
/*序列化和反序列化二叉搜索树*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    std::string serialize(TreeNode *root)
    {
        std::string s;
        if (!root)
        {
            return s;
        }

        std::queue<TreeNode *> T;
        T.push(root);
        while (!T.empty())
        {
            int n = T.size();
            while (n--)
            {
                TreeNode *node = T.front();
                T.pop();
                if (!node)
                    s += "#";
                else
                {
                    s += std::to_string(node->val) + std::string(1, '!');
                    T.push(node->left);
                    T.push(node->right);
                }
            }
        }
        return s;
    }

    TreeNode *deserialize(std::string data)
    {
        TreeNode *root = nullptr;
        if (data.empty())
            return root;

        std::queue<TreeNode **> q;
        q.push(&root);
        int i = 0;
        while (i < data.size())
        {
            int n = q.size();
            while (n--)
            {
                TreeNode **node = q.front();
                q.pop();
                int post = data.find('!', i);
                std::string ans = data.substr(i, post - i);
                i = post + 1;
                if (ans == "#")
                    *node = nullptr;
                else
                {
                    *node = new TreeNode(stoi(ans));
                    q.push(&(*node)->left);
                    q.push(&(*node)->right);
                }
            }
        }
        return root;
    }
};
