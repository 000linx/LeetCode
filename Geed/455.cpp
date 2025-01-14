#include <iostream>
#include <algorithm>
#include <vector>

class Solution
{
public:
    int findContentChildren(std::vector<int> &g, std::vector<int> &s)
    {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        int ans = 0, temp = 0;
        while (ans < g.size() && temp < s.size())
        {
            if (g[ans] <= s[temp])
            {
                ans++;
            }
            temp++;
        }
        return ans;
    }
};