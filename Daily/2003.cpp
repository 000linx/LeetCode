#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<functional>

class Solution
{
public:
    std::vector<int> smallestMissingValueSubtree(std::vector<int> &parents, std::vector<int> &nums){
        int n = parents.size();
        std::vector<int> ans(n,1);
        std::vector<int> vis(n,0);
        std::unordered_set<int> s;
        std::vector<std::vector<int>> v(n);
        for (int i = 1; i < n; i++)
        {
            v[parents[i]].push_back(i);
        }
        std::function<void(int)> dfs = [&](int node) {
            if(vis[node])
                return;
            vis[node] = 1;
            s.insert(nums[node]);
            for (auto i : v[node])
                dfs(i);
        };
        int x = 1, y = -1;
        for (int i = 0; i < n ; i++)
        {
            if(nums[i] == 1)
            {
                y = i;
                break;
            }
        }
        while(y != -1)
        {
            dfs(y);
            while(s.count(x))
            {
                x++;
            }
            ans[y] = x;
            y = parents[y];
        }
        return ans;
    }   
};