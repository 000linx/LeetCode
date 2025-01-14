#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

/*动态规划*/
class Solution
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        int n = prices.size();
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            int j = i - 1;
            ans += std::max(prices[i] - prices[j], 0);
        }
        return ans;
    }
};