#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <cstring>

class Solution
{
public:
    int minimumVisitedCells(std::vector<std::vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        std::set<int> row[n], col[m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i + j > 0)
                {
                    row[i].insert(j);
                    col[j].insert(i);
                }
            }
        }

        int f[n][m];
        memset(f, -1, sizeof(f));
        std::queue<std::pair<int, int>> q;
        q.push(std::pair<int, int>(0, 0));
        f[0][0] = 1;
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            int x = p.first, y = p.second;

            auto it = row[x].upper_bound(y);
            while (it != row[x].end())
            {
                if (*it > grid[x][y] + y)
                {
                    break;
                }
                q.push(std::pair<int, int>(x, *it));
                f[x][*it] = f[x][y] + 1;
                col[*it].erase(x);
                it = row[x].erase(it);
            }
            it = col[y].upper_bound(x);
            while (it != col[y].end())
            {
                if (*it > grid[x][y] + x)
                {
                    break;
                }
                q.push(std::pair<int, int>(*it, y));
                f[*it][y] = f[x][y] + 1;
                row[*it].erase(y);
                it = col[y].erase(it);
            }
        }
        return f[n - 1][m - 1];
    }
};