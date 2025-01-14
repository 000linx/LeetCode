#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

/*
买入为负，卖出为正
对于第i天结束手上股票的状态
1.手上有股票    stock[i][0]
2.手上没有股票，并且还是在冻结期 stock[i][1]
3.手上没有股票，不在冻结期 stock[i][2]

第i天的状态从第i - 1天得来
那么对于第i天手上有股票的来说，第i - 1天的情况有两种
1.在第i天买的股票(即第i - 1天没有股票并且不在冻结期)stock[i - 1][2] - prices[i]
2.在第i - 1天买的股票 stock[i- 1][0]

对于手上没有股票并且是在冻结期的来说，第i天是卖出股票，第i - 1天的情况为
1.手上持有一支股票 stock[i-1][0] + prices[i]

对于手上没有股票并且不在冻结期的来说，第i天未进行操作，第i - 1天的情况为
1.第i - 1天是冻结期所以手上没有股票stock[i -1][1]
2.第i - 1天不是冻结期并且手上没有股票stock[i -1][2]

*/
class Solution
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        int n = prices.size();
        std::vector<std::vector<int>> stock(n);
        stock[0][0] = -prices[0];

        for (int i = 1; i <= n; ++i)
        {
            stock[i][0] = std::max(stock[i - 1][0], stock[i - 1][2] - prices[i]);
            stock[i][1] = stock[i - 1][0] + prices[i];
            stock[i][2] = std::max(stock[i - 1][1], stock[i - 1][2]);
        }
        return std::max(stock[n - 1][1], stock[n - 1][2]);
    }
};