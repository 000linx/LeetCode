#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

class Solution
{
public:
    int countSeniors(std::vector<std::string> &details)
    {
        int ans = 0;
        for(auto i :details)
        {
            std::string s = i;
            int test = (s[11] - '0') * 10 + (s[12] - '0');
            if(test > 60)
            {
                ans++;
            }
        }
        return ans;
    }
};