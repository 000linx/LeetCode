#include <iostream>
#include <vector>
#include<stack>
#include <algorithm>
#include <math.h>

class StockSpanner
{
    std::stack<std::pair<int, int>> s;
    int day = -1;
public:
    StockSpanner()
    {
        s.emplace(-1, INT_MAX);
    }

    int next(int price)
    {
        while(price >= s.top().second){
            s.pop();
        }
        int span = ++day - s.top().first;
        s.emplace(day, price);
        return span;
    }
};