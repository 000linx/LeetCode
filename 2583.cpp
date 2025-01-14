#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


/*二叉树层序和*/

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
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        std::vector<long long> ans;
        std::queue<TreeNode *> q;
        q.push(root);
        int temp = 0;
        while(!q.empty()){
            long long sum = 0;
            for (int i = q.size(); i--;){
                auto node = q.front();
                q.pop();
                sum += node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            ans.push_back(sum);
            temp++;
        }
        sort(ans.begin(), ans.end(),std::greater<long long>());
        if(temp < k){
            return -1;
        }
        return ans[k - 1];
    }
};