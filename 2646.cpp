#include <iostream>
#include <vector>
#include <set>
#include <functional>
/*深度优先搜索 + 动态规划*/

class Solution
{
public:
    int minimumTotalPrice(int n, std::vector<std::vector<int>> &edges, std::vector<int> &price, std::vector<std::vector<int>> &trips)
    {
        std::vector<std::vector<int>> v(n);
        for(auto &i:edges){
            int x = i[0], y = i[1];
            v[x].push_back(y);
            v[y].push_back(x);
        }

        std::vector<int> cnt(n);
        for(auto &i:trips){
            int end = i[1];
            std::function<bool(int, int)> dfs = [&](int x, int y) -> bool
            {
                if(x == end)
                {
                    cnt[x]++;
                    return true;
                }
                for(int j:v[x]){
                    if (j != y && dfs(j,x)){
                        cnt[x]++;
                        return true;
                    }
                }
                return false;
            };
            dfs(i[0], -1);
        }

        std::function<std::pair<int, int>(int, int)> dfs = [&](int x, int y) -> std::pair<int, int>
        {
            int not_half = price[x] * cnt[x];
            int half = not_half / 2;
            for(int j:v[x])
            {
                if(j != y)
                {
                    auto [NH, H] = dfs(j, x);
                    not_half += std::min(NH, H);
                    half += NH;
                }
            }
            return {not_half,half};
        };
        auto [nh, h] = dfs(0, -1);
        return std::min(nh, h);
    }
};