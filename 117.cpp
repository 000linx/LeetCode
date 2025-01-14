#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

/*二叉树*/
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{

public:
    Node *connect(Node *root)
    {
        if(root == NULL)
            return NULL;
        std::queue<Node *> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            Node *node;
            for (int i = 1; i <= n; i++)
            {
                Node *t = q.front();
                q.pop();
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
                if(i!=1)
                    node->next = t;
                node = t;
            }
        }
        return root;
    }
};