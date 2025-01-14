#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

class Solution
{
public:
    long long maxKelements(std::vector<int> &nums, int k)
    {
        long long ans = 0;
        std::priority_queue<int> q(nums.begin(), nums.end());
        for (int i = 0; i < k; i++)
        {
            double Max = q.top();
            q.pop();
            ans += Max;
            q.push(ceil(Max / 3));
        }
            return ans;

    }
};

int main()
{

    Solution s;
    std::vector<int> v = {1, 10, 3, 3, 3};
    s.maxKelements(v,3);
    return 0;
}