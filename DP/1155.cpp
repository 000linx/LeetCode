#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
/*
    动态规划
对于最后一次选择加上的数字是否是等于target
那么就有dp[i][j]表示第i个骰子有j种方案
(dp[i][j] = dp[i][j] + dp[i - 1][j -1]) % mod

*/


class Solution
{
public:
    const int Mod = 1e9 + 7;
    int numRollsToTarget(int n, int k, int target)
    {
        if(n*k<target || target < n)
        {
            return 0;
        }
        std::vector<std::vector<int>> v(n + 1, std::vector<int>(target + 1));
        v[0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= target;j++)
            {
                for (int q = 1; q <= k;q++)
                {
                    if(j - q >= 0)
                    {
                        v[i][j] = (v[i][j] + v[i - 1][j - q]) % Mod;
                    }
                }
            }
        }
        return v[n][target];
    }
};