#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>


/*
动态规划
只是买了一次还没卖 Max = max(不操作,今天选择购买)
完成一次买卖 Max = (不操作，在买一次的前提下卖出)
进行了一次买卖，然后又买了一次 Max = max(不操作,在完成买卖的前提下买一次)
完成两次买卖 Max = max(不操作,在完成买的前提下卖出)
*/

class Solution
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        int n = prices.size();
        int a = -prices[0], one = 0;
        int b = -prices[0], two = 0;
        for (int i = 1; i < n; ++i)
        {
            a = std::max(a, -prices[i]);
            one = std::max(one, a + prices[i]);
            b = std::max(b, one - prices[i]);
            two = std::max(two, b + prices[i]);
        }
        return two;
    }
};

int main()
{
    Solution s;
    std::vector<int> v1(8);
    for (int i = 0; i < 8;i++)
    {
        std::cin >> v1[i];
    }
    s.maxProfit(v1);
    return 0;
}