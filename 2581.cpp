#include <iostream>
#include <vector>
#include <unordered_set>
#include <functional>

using LL = long long;

class Solution
{
public:
    int rootCount(std::vector<std::vector<int>> &edges, std::vector<std::vector<int>> &guesses, int k)
    {
        std::vector<std::vector<int>> g(edges.size() + 1);
        for (auto &e : edges)
        {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x); // 建图
        }

        std::unordered_set<LL> s;
        for (auto &e : guesses)
        {                                    // guesses 转成哈希表
            s.insert((LL)e[0] << 32 | e[1]); // 两个 4 字节数压缩成一个 8 字节数
        }

        int ans = 0, cnt0 = 0;
        std::function<void(int, int)> dfs = [&](int x, int fa)
        {
            for (int y : g[x])
            {
                if (y != fa)
                {
                    cnt0 += s.count((LL)x << 32 | y); // 以 0 为根时，猜对了
                    dfs(y, x);
                }
            }
        };
        dfs(0, -1);

        std::function<void(int, int, int)> reroot = [&](int x, int fa, int cnt)
        {
            ans += cnt >= k; // 此时 cnt 就是以 x 为根时的猜对次数
            for (int y : g[x])
            {
                if (y != fa)
                {
                    reroot(y, x, cnt - s.count((LL)x << 32 | y)   // 原来是对的，现在错了
                                     + s.count((LL)y << 32 | x)); // 原来是错的，现在对了
                }
            }
        };
        reroot(0, -1, cnt0);
        return ans;
    }
};
