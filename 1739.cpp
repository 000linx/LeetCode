#include <iostream>
#include <vector>

/*双指针*/

class Solution
{
public:
    int maximumScore(std::vector<int> &nums, int k)
    {
        int n = nums.size();
        int ans = nums[k], Min = nums[k];
        int l = k, r = k;
        for (int i = 0; i < n - 1; i++)
        {
            if (r == n - 1 || l && nums[l - 1] > nums[r + 1])
            {
                Min = std::min(Min, nums[--l]);
            }
            else
            {
                Min = std::min(Min, nums[++r]);
            }
            ans = std::max(ans, Min * (r - l + 1));
        }
        return ans;
    }
};