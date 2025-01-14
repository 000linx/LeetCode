#include <iostream>
#include <queue>
#include <vector>
/*二叉树 + BFS*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};

class Solution
{
public:
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        std::queue<TreeNode *> q;
        q.emplace(root);
        bool ok = false;
        while(!q.empty()){
            int size = q.size();
            std::vector<TreeNode *> v;
            for (int i = 0; i < size ;i++){
                TreeNode *node = q.front();
                q.pop();
                if(ok){
                    v.emplace_back(node);
                }
                if(node -> left){
                    q.emplace(node->left);
                    q.emplace(node->right);
                }
            }
            if(ok){
                for (int i = 0, j = size - 1; i < j; i++,j--){
                    std::swap(v[i]->val, v[j]->val);
                }
            }
            ok ^= true;
        }
        return root;
    }
};