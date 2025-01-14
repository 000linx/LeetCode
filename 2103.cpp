#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <map>
class Solution
{
public:
    int countPoints(std::string rings)
    {
        int n = rings.size(),ans = 0;
        std::map<int, std::string> m;
        for (int i = 0; i < n; i+=2)
        {
            if (m[rings[i + 1]-'0'].find(rings[i]) == std::string::npos)
            {
                m[rings[i + 1]-'0'] += rings[i];
                if (m[rings[i + 1] -'0'].size() == 3)
                    ans++;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    std::string v = "B0R0G0R9R0B0G0";
    s.countPoints(v);
    return 0;
}