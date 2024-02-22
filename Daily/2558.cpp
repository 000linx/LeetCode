#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include<queue>
class Solution
{
public:
    long long pickGifts(std::vector<int> &gifts, int k)
    {
        std::priority_queue<int>q(gifts.begin(), gifts.end());
        long long ans = 0;
        for (int i = 0; i < k; i++)
        {
            int res = q.top();
            q.pop();
            q.push(sqrt(res));
        }
        while(!q.empty())
        {
            ans += q.top();
            q.pop();
        }
            return ans;
    }
};
