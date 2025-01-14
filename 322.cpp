#include <iostream>
#include <vector>
#include <functional>

class Solution
{
public:
    int coinChange(std::vector<int> &coins, int amount)
    {
        int ans = 0, n = coins.size();
        std::vector<std::vector<int>> v(n, std::vector<int>(amount + 1, -1));
        std::function<int(int, int)> dfs = [&](int i, int j) -> int
        {
            if (i < 0)
            {
                return j == 0 ? 0 : INT_MAX / 2;
            }
            int &res = v[i][j];
            if (res != -1)
            {
                return res;
            }
            if (j < coins[i])
            {
                return res = dfs(i - 1, j);
            }
            return res = std::min(dfs(i - 1, j), dfs(i, j - coins[i]) + 1);
        };
        ans = dfs(n - 1, amount);
        return ans < INT_MAX / 2 ? ans : -1;
    }
};