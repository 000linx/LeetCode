#include <iostream>
#include <vector>
#include <numeric>

class Solution
{
public:
    int candy(std::vector<int> &ratings)
    {
        int n = ratings.size();
        if (n < 2)
        {
            return n;
        }
        std::vector<int> v(n, 1);
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                v[i] = v[i - 1] + 1;
            }
        }

        for (int i = n - 1; i > 0; i--)
        {
            if (ratings[i - 1] > ratings[i])
            {
                v[i - 1] = std::max(v[i - 1], v[i] + 1);
            }
        }
        return std::accumulate(v.begin(), v.end(), 0);
    }
};