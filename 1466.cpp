#include <iostream>
#include <functional>
#include <vector>
#include <set>

class Solution
{
public:
    int dfs(auto x, auto ne, std::vector<std::vector<std::pair<int, int>>> &v)
    {
        int ans = 0;
        for (auto &i : v[x])
        {
            if (i.first == ne)
            {
                continue;
            }
            ans += i.second + dfs(i.first, x, v);
        }
        return ans;
    }
    int minReorder(int n, std::vector<std::vector<int>> &connections)
    {
        std::vector<std::vector<std::pair<int,int>>> v(n);
        for(auto &i:connections){
            int x = i[0], y = i[1];
            v[x].push_back(std::make_pair(y,1));
            v[y].push_back(std::make_pair(x,0));
        }
        return dfs(0,-1,v);
    }
};