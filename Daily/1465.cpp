#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>


class Solution
{
public:
    const int Mod = 1e9 + 7;
    int max_border(std::vector<int>&v,int border)
    {
        int ans = 0, res = 0;
        for (int i = 0; i < v.size();i++)
        { 
            int a = v[i];
            ans = std::max(a - res, ans);
            res = a;
        }
        return std::max(ans,border - res);
    }
    int maxArea(int h, int w, std::vector<int> &horizontalCuts, std::vector<int> &verticalCuts)
    {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        long long ans = max_border(horizontalCuts, h) * max_border(verticalCuts, w);
        return ans % Mod;
    }
};

