#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>

/*动态规划*/
class Solution
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        int ans = 0,Max = INT_MAX;
        for (int i = 0; i < prices.size(); i++)
        {
            Max = std::min(Max, prices[i]);
            ans = std::max(ans,prices[i] - Max);
        }
        return ans;
    }
};