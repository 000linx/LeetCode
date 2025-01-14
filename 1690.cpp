#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

/*动态规划*/
class Solution
{
public:
    int stoneGameVII(std::vector<int> &stones)
    {
        int n = stones.size();
        std::vector<int> v(n + 1);
        std::partial_sum(stones.begin(), stones.end(), v.begin() + 1);
        std::vector<std::vector<int>> memory(n, std::vector<int>(n + 1));

        std::function<int(int, int)> dfs = [&](int i, int j) -> int {
            if(i == j){
                return 0;
            }
            int &res = memory[i][j];
            if(res){
                return res;
            }
            //i + 1代表移除左边，j - 1代表移除右边
            return res = std::max(v[j + 1] - v[i + 1] - dfs(i + 1, j), v[j] - v[i] - dfs(i, j - 1));
        };

        return dfs(0, n - 1);
    }
};