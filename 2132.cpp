#include <iostream>
#include <vector>

class Solution
{
public:
    bool possibleToStamp(std::vector<std::vector<int>> &grid, int stampHeight, int stampWidth)
    {
        int n = grid[0].size(), m = grid.size();

        std::vector<std::vector<int>> v(m + 1, std::vector<int>(n + 1));
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                v[i + 1][j + 1] = v[i + 1][j] + v[i][j + 1] - v[i][j] + grid[i][j];
            }
        }

        std::vector<std::vector<int>> diff(m + 2, std::vector<int>(n + 2));
        for (int i = stampHeight; i <= m; i++){
            for (int j = stampWidth; j <= n; j++){
                int x = i - stampHeight + 1;
                int y = j - stampWidth + 1;
                if(v[i][j] - v[i][y - 1] - v[x - 1][j] + v[x - 1][y - 1] == 0){
                    diff[x][y]++;
                    diff[x][j + 1]--;
                    diff[i + 1][y]--;
                    diff[i + 1][j + 1]++;
                }

            }
        }

        for (int i = 0; i < m; i ++){
            for (int j = 0; j < n; j++){
                diff[i + 1][j + 1] += diff[i + 1][j] + diff[i][j + 1] - diff[i][j];
                if(grid[i][j] == 0 && diff[i + 1][j + 1] == 0)
                    return false;
            }
        }

        return true;
    }
};