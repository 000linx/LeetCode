#include<iostream>
#include <vector>

/*动态规划*/
class Solution
{
public:
    int minCostClimbingStairs(std::vector<int> &cost)
    {
        int n = cost.size();
        std::vector<int> f(n + 1);
        for (int i = 2; i <= n; i++)
        {
            f[i] = std::min(f[i - 1] + cost[i - 1], f[i - 2] + cost[i - 2]);
        }
        return f[n];
    }
};
