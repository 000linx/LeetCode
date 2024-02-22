
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
/*
基本动态规划
子问题：对于第i间房子要不要偷
1.要偷，那么总金额ans就等于前i - 2间房子的最大金额加上第i间房子的金额
2.不偷，那么总金额ans就等于前i - 1间房子的最大金额
那么 f(i) = max{f(i - 1) , nums[i] + f(i - 2)}
当房子数为0时，ans为0
当房子房子数为1时，ans = nums[0] 
*/
class Solution
{
public:
    int rob(std::vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        std::vector<int> ans(nums.size() + 1, 0);
        ans[0] = 0;
        ans[1] = nums[0];
        for (int i = 2; i <= nums.size(); i++)
        {
            ans[i] = std::max(ans[i - 1], ans[i - 2] + nums[i - 1]);
        }
        return ans[nums.size()];
    }
};
