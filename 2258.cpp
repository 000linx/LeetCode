#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

class Solution
{
    const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // 返回能否在初始位置停留 t 分钟，并安全到达安全屋
    bool check(std::vector<std::vector<int>> &grid, int t)
    {
        int m = grid.size(), n = grid[0].size();
        std::vector<std::vector<int>> on_fire(m, std::vector<int>(n));
        std::vector<std::pair<int, int>> f;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    on_fire[i][j] = true; // 标记着火的位置
                    f.emplace_back(i, j);
                }
            }
        }
        // 火的 BFS
        auto spread_fire = [&]()
        {
            std::vector<std::pair<int, int>> nf;
            for (auto &[i, j] : f)
            {
                for (auto &[dx, dy] : dirs)
                { // 枚举上下左右四个方向
                    int x = i + dx, y = j + dy;
                    if (0 <= x && x < m && 0 <= y && y < n && !on_fire[x][y] && grid[x][y] == 0)
                    {
                        on_fire[x][y] = true; // 标记着火的位置
                        nf.emplace_back(x, y);
                    }
                }
            }
            f = move(nf);
        };
        while (t-- && !f.empty())
        {                  // 如果火无法扩散就提前退出
            spread_fire(); // 火扩散
        }
        if (on_fire[0][0])
        {
            return false; // 起点着火，寄
        }

        // 人的 BFS
        std::vector<std::vector<int>> vis(m, std::vector<int>(n));
        vis[0][0] = true;
        std::vector<std::pair<int, int>> q{{0, 0}};
        while (!q.empty())
        {
            std::vector<std::pair<int, int>> nq;
            for (auto &[i, j] : q)
            {
                if (on_fire[i][j])
                    continue; // 人走到这个位置后，火也扩散到了这个位置
                for (auto &[dx, dy] : dirs)
                { // 枚举上下左右四个方向
                    int x = i + dx, y = j + dy;
                    if (0 <= x && x < m && 0 <= y && y < n && !on_fire[x][y] && !vis[x][y] && grid[x][y] == 0)
                    {
                        if (x == m - 1 && y == n - 1)
                        {
                            return true; // 我们安全了…暂时。
                        }
                        vis[x][y] = true; // 避免反复访问同一个位置
                        nq.emplace_back(x, y);
                    }
                }
            }
            q = move(nq);
            spread_fire(); // 火扩散
        }
        return false; // 人被火烧到，或者没有可以到达安全屋的路
    }

public:
    int maximumMinutes(std::vector<std::vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        // 这里我用开区间二分（其它写法也可以）
        int left = -1, right = m * n + 1;
        while (left + 1 < right)
        {
            int mid = (left + right) / 2;
            (check(grid, mid) ? left : right) = mid;
        }
        return left < m * n ? left : 1'000'000'000;
    }
};

