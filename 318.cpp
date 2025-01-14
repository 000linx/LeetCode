#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

/*位运算*/
class Solution
{
public:
    int maxProduct(std::vector<std::string> &words)
    {
        int ans = 0;
        int n = words.size();
        std::vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            for(auto &c : words[i])
                v[i] |= 1 << (c - 'a');
            for (int j = 0; j < i; j++)
            {
                int l = words[i].length(), r = words[j].length();
                if((v[i] & v[j]) == 0)
                    ans = std::max(ans, l * r);
            }
        }
            return ans;
    }
};

