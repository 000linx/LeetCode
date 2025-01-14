#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<numeric>
class Solution
{
public:
    int earliestFullBloom(std::vector<int> &plantTime, std::vector<int> &growTime)
    {
        std::vector<int> v(plantTime.size());
        std::iota(v.begin(), v.end(), 0);
        sort(v.begin(), v.end(), [&](int x, int y)
             { return growTime[x] > growTime[y]; });
        int day = 0, cnt = 0;
        for(int i:v)
        {
            cnt += plantTime[i];
            day = std::max(day, cnt + growTime[i]);
        }
        return day;
    }
};