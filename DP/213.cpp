#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

/*
动态规划
第一间房子要不要偷
要偷：nums[1]和nums[n - 1]不能偷,计算从nums[2】到nums[n - 2]再加上nums[0]
不偷：计算从nums[1]到nums[n - 1]
*/
class Solution
{
public:
    int ans(std::vector<int> &nums,int l, int r)
    {
        int first = 0, second = 0;
        for (int i = l; i <= r; i++)
        {
            int res = std::max(first, second + nums[i]);
            second = first;
            first = res;
        }
        return first;
    }
    int rob(std::vector<int> &nums)
    {
        int n = nums.size();
        return std::max(nums[0]+ans(nums,2,n - 2),ans(nums,1,n - 1));
    }
};
