#include <iostream>
#include <algorithm>
#include <vector>

class Solution
{
public:
    const int Mod = 1e9 + 7;
    int countWays(std::vector<std::vector<int>> &ranges)
    {
        std::sort(ranges.begin(), ranges.end());
        int ans = 1, Max = -1;
        for (auto &n : ranges)
        {
            if (n[0] > Max)
            {
                ans = ans * 2 % Mod;
            }
            Max = std::max(Max, n[1]);  
        }
        return ans;
    }
};