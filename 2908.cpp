#include <iostream>
#include <vector>

class Solution
{
public:
    int minimumSum(std::vector<int> &nums)
    {
        int n = nums.size();
        int ans = INT_MAX;
        std::vector<int> v(n);
        v[n - 1] = nums[n - 1];
        for (int i = n - 2; i > 1; i--)
        {
            v[i] = std::min(v[i + 1], v[i]);
        }

        int pre = nums[0];
        for (int i = 1; i < n - 1; i++)
        {
            if (pre < nums[i] && nums[i] > v[i + 1])
            {
                ans = std::min(ans, pre + nums[i] + v[i + 1]);
            }
            pre = std::min(pre, nums[i]);
        }
        return ans = INT_MAX ? -1 : ans;
    }
};