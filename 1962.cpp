#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

class Solution
{
public:
    int minStoneSum(std::vector<int> &piles, int k)
    {
        make_heap(piles.begin(), piles.end());
        while (k-- && piles[0] != 1)
        {
            pop_heap(piles.begin(), piles.end());
            piles.back() -= piles.back() / 2;
            push_heap(piles.begin(), piles.end());
        }
        return accumulate(piles.begin(), piles.end(), 0);
    }
};