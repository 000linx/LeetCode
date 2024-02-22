#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int findTheLongestBalancedSubstring(std::string s)
    {
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            if(s[i] == '0')
            {
                int sum = 0;
                cnt++;
                bool ok = true;
                for (int j = i + 1; j < n; j++)
                {
                    if(s[j] == '0' && ok)
                        cnt++;
                    else if(s[j] == '1')
                    {
                        sum++;
                        if(sum == cnt)
                            ans = std::max(ans, cnt * 2);
                        ok = false;
                    }
                    else if(s[j] == '0' && !ok)
                        break;
                }
            }
        }
            return ans;
    }
};

int main()
{
    Solution s1;
    std::string v = "000011";
    s1.findTheLongestBalancedSubstring(v);

    return 0;
}