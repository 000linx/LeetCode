#include <iostream>
#include <functional>
#include <set>
#include <vector>

/*动态规划 + 递归*/
class Solution
{
public:
    long long maxTaxiEarnings(int n, std::vector<std::vector<int>> &rides)
    {
        std::vector<std::vector<std::pair<int, int>>> v(n+1);
        for(auto &i:rides){
            int start = i[0], end = i[1], tips = i[2];
            v[end].emplace_back(start,end - start + tips);
        }
        std::vector<long long> memory(n + 1,-1);
        std::function<long long(int)> dfs = [&](int end) -> long long {
           if(end == 1)
               return 0;
           auto &ans = memory[end];
           if(ans != -1)
               return ans;
           ans = dfs(end - 1);
           for(auto &[start,tips]:v[end]){
               ans = std::max(ans, dfs(start) + tips);
           }
           return ans;
        };
        return dfs(n);
    }
};