#include <iostream>
#include <vector>

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
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        if (original == nullptr || original == target)
        {
            return cloned;
        }

        TreeNode *left = getTargetCopy(original->left, cloned->left, target);
        if (left)
        {
            return left;
        }
        return getTargetCopy(original->right, cloned->right, target);
    }
};