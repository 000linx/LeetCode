#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>
#include<functional>
class Solution
{
public:
    long long countPairs(int n, std::vector<std::vector<int>> &edges)
    {
        std::vector<int> gr[n];
        for (auto &e : edges)
        {
            int a = e[0], b = e[1];
            gr[a].push_back(b);
            gr[b].push_back(a);
        }
        bool vis[n];
        memset(vis, 0, sizeof(vis));
        std::function<int(int)> dfs = [&](int i)
        {
            if (vis[i])
            {
                return 0;
            }
            vis[i] = true;
            int cnt = 1;
            for (int j : gr[i])
            {
                cnt += dfs(j);
            }
            return cnt;
        };
        long long ans = 0, sum = 0;
        for (int i = 0; i < n; ++i)
        {
            int t = dfs(i);
            ans += sum * t;
            sum += t;
        }
        return ans;
    }
};