#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

class Solution
{
    using ll = long long;
    const ll Mod = 1e9 + 7;
public:
    int sumDistance(std::vector<int> &nums, std::string s, int d)
    {
        ll ans = 0;
        int n = nums.size();
        std::vector<ll> v(n);
        for (int i = 0; i < n; i++)
        {
            if(s[i] == 'R')
                v[i] = nums[i] + d;
            else
                v[i] = nums[i] - d;
        }
        sort(v.begin(), v.end());
        for (int i = 1; i < n; i++)
        {
            ans += 1ll * (v[i] - v[i - 1]) * i % Mod * (n - i) % Mod;
            ans %= Mod;
        }
            return ans ;
    }
};
