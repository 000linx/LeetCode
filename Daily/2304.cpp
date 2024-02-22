#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

/*
从第一行任意一个单元格出发到最后一行单元格的最小代价和
grid[0][0]代表着第一行的第一个单元格，假设需要到达的单元格为grid[m - 1][n - 1]
上一行的每个单元格与和下一行的所有单元格之间有条边

*/
class Solution
{
public:
    int minPathCost(std::vector<std::vector<int>> &grid, std::vector<std::vector<int>> &moveCost)
    {
        int m = grid.size(), n = grid[0].size();
        std::vector<std::vector<int>> memory(m, std::vector<int>(n));
        std::function<int(int ,int)>dfs = [&](int a, int b) -> int {
            if(a == m - 1)
                return grid[a][b];
            auto &sum = memory[a][b];
            if(sum)
                return sum;

            sum = INT_MAX;
            for (int i = 0; i < n; i++){
                sum = std::min(sum, dfs(a + 1, i) + moveCost[grid[a][b]][i]);
            }
            sum += grid[a][b];
            return sum;
        };
        int ans = INT_MAX;
        for (int i = 0; i < n; i++){
            ans = std::min(ans, dfs(0, i));
        }
            return ans;
    }
};


int main(){
    Solution s;
    std::vector<std::vector<int>> v = {{5, 3}, {4, 0}, {2, 1}};
    std::vector<std::vector<int>> v1 = {{9,8},{1,5},{10,12},{18,6},{2,4},{14,3}};
    s.minPathCost(v,v1);
    return 0;
}