#include <iostream>
#include <algorithm>
#include <vector>

class Solution
{
public:
    int findMinArrowShots(std::vector<std::vector<int>> &points)
    {
        sort(points.begin(), points.end(), [](const std::vector<int> &a, const std::vector<int> &b)
             { return a[1] < b[1]; });
        int n = points.size();
        int temp = points[0][1];
        int total = 1;
        for (int i = 1; i < n; i++)
        {
            if (points[i][0] > temp)
            {
                temp = points[i][1];
                total++;
            }
        }

        return total;
    }
};