#include <iostream>
#include <vector>
#include <numeric>

class Solution
{
public:
    int minIncrements(int n, std::vector<int> &cost)
    {
        int ans = 0;
        for (int i = n / 2; i > 0; i--)
        {
            ans += std::abs(cost[i * 2 - 1] - cost[i * 2]);
            cost[i - 1] += std::max(cost[i * 2 - 1], cost[i * 2]);
        }
        return 0;
    }
};

int main()
{
    int n = 7;
    Solution s;
    std::vector<int> v = {1, 5, 2, 2, 3, 3, 1};
    s.minIncrements(n, v);
    return 0;
}