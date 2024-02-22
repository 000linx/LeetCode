#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <functional>

class Solution
{
public:
    int maximumInvitations(std::vector<int> &favorite)
    {
        int n = favorite.size();
        std::vector<int> v(n);
        std::vector<std::vector<int>> Map(n);
        std::queue<int> q;
        for(auto i : favorite)
        {
            v[i]++;
        }
        for (int i = 0; i < n; i++)
        {
            if(v[i] == 0)
                q.push(i);
        }
        while(!q.empty())
        {
            int t = q.front();
            q.pop();
            int a = favorite[t];
            Map[a].push_back(t);
            if(--v[a] == 0)
                q.push(a);
        }
        std::function<int(int)> dfs = [&](int i) -> int
        {
            int max_depth = 1;
            for(auto x:Map[i])
            {
                max_depth = std::max(max_depth, dfs(x) + 1);
            }
            return max_depth;
        };
        int max_size = 0, sum_size = 0;
        for (int i = 0; i < n; i++)
        {
            if(v[i] == 0)
                continue;
            v[i] = 0;
            int rs = 1;
            for (int x = favorite[i]; x != i; x =favorite[x])
            {
                v[x] = 0;
                rs++;
            }
            if(rs == 0)
                sum_size += dfs(i) + dfs(favorite[i]);
            else
                max_size = std::max(max_size, rs);
        }
        return std::max(max_size, sum_size);
    }
};

int main()
{
    Solution s;
    std::vector<int> v = {2, 2, 1, 2};
    s.maximumInvitations(v);
    return 0;
}