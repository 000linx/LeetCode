#include<iostream>
#include<vector>

class Solution
{
public:
    int minCount(std::vector<int> &coins)
    {
        int ans = 0;
        for (int i = 0; i < coins.size();i++)
        {
            if(coins[i] == 1)
                ans += 1;
            else if(coins[i] %2 == 0)
                ans += coins[i] / 2;
            else if(coins[i] % 2 != 0)
                ans += coins[i] / 2 + 1;
        }
            return ans;

    }
};