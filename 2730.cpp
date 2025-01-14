#include <iostream>
#include <vector>

class Solution
{
public:
    int longestSemiRepetitiveSubstring(std::string s)
    {
        int ans = 1, n = s.length(),sum = 0,j = 0;
        for (int i = 1; i < n;i++){
            if(s[i] == s[i - 1] && ++sum>1){
                for (++j; s[j] != s[j - 1];j++);
                sum = 1;
            }
            ans = std::max(ans, i - j + 1);
        }
        return ans;
    }
};