#include <iostream>
#include <vector>

/*二叉树*/

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
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        std::vector<TreeNode *> v;
        root->val = 0;

        while(!v.empty()){
            std::vector<TreeNode *> q;
            int sum = 0;
            for (auto node : v){
                if(node->left){
                    q.push_back(node->left);
                    sum += node->left->val;
                }
                if(node->right){
                    q.push_back(node->right);
                    sum += node->right->val;
                }
            }

            for (auto node : v){
                int temp = (node->left ? node->left->val : 0) + ((node->right ? node->right->val : 0));
                if(node->left){
                    node->left->val = sum - temp;
                }
                if(node->right){
                    node->right->val = sum - temp;
                }
            }
            v = std::move(q);
        }
        return root;
    }
};
