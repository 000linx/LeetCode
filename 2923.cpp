#include <iostream>
#include <vector>

class Solution
{
public:
    int findChampion(std::vector<std::vector<int>> &grid)
    {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    cnt++;
                }
                if (cnt == m - 1)
                {
                    ans = i;
                    break;
                }
            }
            if (ans != 0)
            {
                break;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    std::vector<std::vector<int>> v = {{ 0, 1 },{0,0}};
    s.findChampion(v);
    return 0;
}