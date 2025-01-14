#include <iostream>
#include <vector>
#include <numeric>
#include <math.h>

class Solution
{
public:
    long long minCost(std::vector<int> &nums, int x)
    {
        int n = nums.size();
        std::vector<int> v(nums);
        long long ans = std::accumulate(v.begin(), v.end(), 0LL);
        for (int i = 1; i < n; i++){
            for (int j = 0; j < n;j ++){
                v[j] = std::min(v[j], nums[(i + j) % n]);
            }
            ans = std::min(ans, static_cast<long long>(i) * x + std::accumulate(v.begin(), v.end(), 0LL));
        }
        return ans;
    }
};