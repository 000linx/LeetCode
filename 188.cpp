#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
/*
动态规划

子问题
在第i次交易时我们手上是否是持有股票得到的最大的利润
1.手上有股票，该股票是第i天买的，还是第i - 1天买的
如果是第i天买的，那么我们在第i - 1天的时候手上没有股票，那么手上的钱就是之前卖的钱减去当天买股票的钱
如果是第i-1天买的，在手上有股票的情况下，那么手上的钱就是之前的买股票剩的钱
2.手上没有股票，在第i天卖的。还是在第i-1天卖的
如果是第i天卖的，那么我们在第 i-1天手上是有股票的，手上的钱就是之前买完股票剩的钱加上卖完得到的钱
如果不是第i天卖出的，那么我们在第i - 1天的时候手上是没有股票的，那么手上的钱就是之前卖完股票剩的钱

在n天之后，手上没有股票的利润一定大于手上没有股票的利润

*/
class Solution
{
public:
    int maxProfit(int k, std::vector<int> &prices)
    {
        int n = prices.size();
        if(n == 0)
            return 0;
        k = std::min(k, n / 2);
        std::vector<int> b(k + 1);
        std::vector<int> s(k + 1);
        b[0] = -prices[0];
        s[0] = 0;
        for (int i = 1; i <= k; i++)
        {
            s[i] = b[i] = INT_MIN / 2;
        }
        for (int i = 1; i <= n; i++)
        {
            b[0] = std::max(b[0], s[0] - prices[i]);
            for (int j = 1; j <= k; j++)
            {
                b[j] = std::max(b[j], s[j] - prices[i]);
                s[j] = std::max(s[j], b[j - 1] + prices[i]);
            }
        }
        int ans = *max_element(s.begin(), s.end());
        return ans;
    }
};