#include <iostream>
#include <algorithm>
#include <vector>

class Solution
{
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>> &intervals)
    {
        int ans = 0;
        if (intervals.empty())
        {
            return ans;
        }
        sort(intervals.begin(), intervals.end(), [](std::vector<int> a, std::vector<int> b)
             { return a[1] < b[1]; });
        int n = intervals.size();
        int temp = intervals[0][1];
        for (int i = 1; i < n; i++)
        {
            if (temp > intervals[i][0])
            {
                ans++;
            }
            else
            {
                temp = intervals[i][1];
            }
        }

        return ans;
    }
};