#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <functional>
#include <array>


/*LCA模板*/

class Solution
{
public:
    std::vector<int> minOperationsQueries(int n, std::vector<std::vector<int>> &edges, std::vector<std::vector<int>> &queries)
    {
        std::vector<std::vector<std::pair<int, int>>> g(n);
        for (auto &e : edges)
        {
            int x = e[0], y = e[1], w = e[2] - 1;
            g[x].emplace_back(y, w);
            g[y].emplace_back(x, w);
        }

        int m = 32 - __builtin_clz(n);
        std::vector<std::vector<int>> pa(n, std::vector<int>(m, -1));
        std::vector<std::vector<std::array<int, 26>>> cnt(n, std::vector<std::array<int, 26>>(m));
        std::vector<int> depth(n);
        std::function<void(int, int)> dfs = [&](int x, int fa)
        {
            pa[x][0] = fa;
            for (auto [y, w] : g[x])
            {
                if (y != fa)
                {
                    cnt[y][0][w] = 1;
                    depth[y] = depth[x] + 1;
                    dfs(y, x);
                }
            }
        };
        dfs(0, -1);

        for (int i = 0; i < m - 1; i++)
        {
            for (int x = 0; x < n; x++)
            {
                int p = pa[x][i];
                if (p != -1)
                {
                    int pp = pa[p][i];
                    pa[x][i + 1] = pp;
                    for (int j = 0; j < 26; ++j)
                    {
                        cnt[x][i + 1][j] = cnt[x][i][j] + cnt[p][i][j];
                    }
                }
            }
        }

        std::vector<int> ans;
        for (auto &q : queries)
        {
            int x = q[0], y = q[1];
            int path_len = depth[x] + depth[y]; 
            int cw[26]{};
            if (depth[x] > depth[y])
            {
                std::swap(x, y);
            }

            for (int k = depth[y] - depth[x]; k; k &= k - 1)
            {
                int i = __builtin_ctz(k);
                int p = pa[y][i];
                for (int j = 0; j < 26; ++j)
                {
                    cw[j] += cnt[y][i][j];
                }
                y = p;
            }

            if (y != x)
            {
                for (int i = m - 1; i >= 0; i--)
                {
                    int px = pa[x][i], py = pa[y][i];
                    if (px != py)
                    {
                        for (int j = 0; j < 26; j++)
                        {
                            cw[j] += cnt[x][i][j] + cnt[y][i][j];
                        }
                        x = px;
                        y = py;
                    }
                }
                for (int j = 0; j < 26; j++)
                {
                    cw[j] += cnt[x][0][j] + cnt[y][0][j];
                }
                x = pa[x][0];
            }

            int lca = x;
            path_len -= depth[lca] * 2;
            ans.push_back(path_len - *std::max_element(cw, cw + 26));
        }
        return ans;
    }
};
