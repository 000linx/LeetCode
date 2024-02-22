#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

class Solution
{
public:
    int countDigits(int num)
    {
        std::string s = std::to_string(num);
        int ans = 0;
        for (int i = 0; i < s.size();i++)
        {
            if(num%s[i] - '0' == 0)
                ans++;
        }
            return ans;
    }
};