#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

const int MX = 1e5;
bool np[MX + 1];
int init = []()
{
    np[1] = true;
    for (int i = 2; i * i <= MX; i++)
    {
        if (!np[i])
        {
            for (int j = i * i; j <= MX; j += i)
            {
                np[j] = true;
            }
        }
    }
    return 0;
}();

class Solution
{
public:
    long long countPaths(int n, std::vector<std::vector<int>> &edges)
    {
        std::vector<std::vector<int>> g(n + 1);
        for (auto &e : edges)
        {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        std::vector<int> size(n + 1);
        std::vector<int> nodes;
        std::function<void(int, int)> dfs = [&](int x, int fa)
        {
            nodes.push_back(x);
            for (int y : g[x])
            {
                if (y != fa && np[y])
                {
                    dfs(y, x);
                }
            }
        };

        long long ans = 0;
        for (int x = 1; x <= n; x++)
        {
            if (np[x])
                continue;
            int sum = 0;
            for (int y : g[x])
            { 
                if (!np[y])
                    continue;
                if (size[y] == 0)
                { 
                    nodes.clear();
                    dfs(y, -1);
                    for (int z : nodes)
                    {
                        size[z] = nodes.size();
                    }
                }
                ans += (long long)size[y] * sum;
                sum += size[y];
            }
            ans += sum; 
        }
        return ans;
    }
};