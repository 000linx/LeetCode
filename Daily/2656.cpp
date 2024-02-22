#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int maximizeSum(std::vector<int> &nums, int k)
    {
        int ans = 0;
        int n = nums.size();
        while(k--)
        {
            sort(nums.begin(), nums.end());
            ans += nums[n - 1];
            nums[n - 1] = nums[n - 1] + 1;
        }
        return ans;
    }
};