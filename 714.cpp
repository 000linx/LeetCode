#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
/*
买入为负，卖出为正
对于第i天结束后，手上持有股票的状态
1.手上没有股票 即为stock[i][0]
2.手上有股票 即为stock[i][1]

手上有股票
1.是在第i天买的,那么第i-1天就没有股票即stock[i-1][0] - prices[i]
2.是在第i - 1天买入的,那么代表第i天没进行任何操作即stock[i-1][1]

手上没有股票
1.股票是在第i天卖出的,那么第i - 1天就有股票即为stock[i-1][1] + prices[i] - fee
2.有可能股票是在第i - 1天卖出的,第i天没有操作即为stock[i-1][0]

考虑收益
1.手上没有股票时的收益
即在第i - 1天是卖出的最大利益和在第i天卖出的最大利益之间取最大值
profile[i][0] = max(stock[i-1][0],stock[i-1][1] + prices[i] -fee)
2.手上有股票时的收益
即在第i天买的还是在第i-1天买的之间取最大值
profile[i][1] = max(stock[i - 1][1],stock[i - 1][0] - prices[i])

边界
在第0天结束的时候，手上没有股票收益为0，手上有股票的收益为-prices[0]因为是买入
stock[0][0] = 0,stock[0][1] = -prices[0]
并且手上没有股票的收益是一定大于手上有股票的收益

*/
class Solution
{
public:
    int maxProfit(std::vector<int> &prices, int fee)
    {
        int n = prices.size();
        std::vector<std::vector<int>> stock(n, std::vector<int>(2));
        stock[0][0] = 0, stock[0][1] = -prices[0];
        for (int i = 1; i < n; ++i)
        {
            stock[i][0] = std::max(stock[i - 1][0], stock[i - 1][1] + prices[i] - fee);
            stock[i][1] = std::max(stock[i - 1][1], stock[i - 1][0] - prices[i]);
        }

        return stock[n - 1][0];
    }
};