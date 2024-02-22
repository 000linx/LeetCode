#include <iostream>
#include <vector>
#include<unordered_map>
#include <algorithm>
#include <math.h>
#include<set>


class StockPrice
{
    std::unordered_map<int, int> stock;
    std::vector<std::vector<int>> v;
    std::multiset<int> pre_prices;
    int current_time = 0;

public:

    StockPrice()
    {
    }

    void update(int timestamp, int price)
    {
        current_time = std::max(current_time, timestamp);
        auto check = stock.count(timestamp) ? stock[timestamp] : 0;
        stock[timestamp] = price;
        if (check > 0)
        {
            auto ok = pre_prices.find(check);
            if (ok != pre_prices.end())
            {
                pre_prices.erase(ok);
            }
        }
        pre_prices.emplace(price);
    }

    int current()
    {
        return stock[current_time];
    }

    int maximum()
    {
        return *pre_prices.rbegin();
    }

    int minimum()
    {
        return *pre_prices.begin();
    }
};