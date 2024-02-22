#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

/*树状数组*/
class NumArray
{
private:
    std::vector<int> nums;
    std::vector<int> tree;

    int prefixSum(int i)
    {
        int s = 0;
        for (; i > 0; i &= i - 1)
        { // i -= i & -i 的另一种写法
            s += tree[i];
        }
        return s;
    }

public:
    NumArray(std::vector<int> &nums) : nums(nums.size()), tree(nums.size() + 1)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            update(i, nums[i]);
        }
    }

    void update(int index, int val)
    {
        int delta = val - nums[index];
        nums[index] = val;
        for (int i = index + 1; i < tree.size(); i += i & -i)
        {
            tree[i] += delta;
        }
    }

    int sumRange(int left, int right)
    {
        return prefixSum(right + 1) - prefixSum(left);
    }
};
