#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <queue>

/*贪心 + 优先队列*/

class Solution
{
public:
    int magicTower(std::vector<int> &nums)
    {
        if (std::accumulate(nums.begin(), nums.end(), 0LL) < 0)
        {
            return -1;
        }
        int ans = 0;
        long long hp = 1;
        std::priority_queue<int> h;
        for (int x : nums)
        {
            if (x < 0)
            {
                h.push(-x);
            }
            hp += x;
            if (hp < 1)
            {
                hp += h.top();
                h.pop();
                ans++;
            }
        }
        return ans;
    }
};