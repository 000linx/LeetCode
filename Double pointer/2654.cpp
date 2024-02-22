#include <iostream>
#include <vector>
#include <algorithm>

/*双指针 + 贪心*/
class Solution
{
public:
    int addMinimum(std::string word)
    {
        std::string s = "abc";
        int n = word.size();
        int ans = 0;
        for (int i = 0, j = 0; j < n; i = (i + 1) % 3)
        {
            if (word[j] != s[i])
            {
                ans++;
            }
            else
            {
                j++;
            }
        }
        if (word[n - 1] != 'c')
        {
            ans += word[n - 1] == 'b' ? 1 : 2;
        }
        return ans;
    }
};