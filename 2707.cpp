#include <iostream>
#include <vector>
#include <unordered_set>

/*动态规划*/

class Solution
{
public:
    int minExtraChar(std::string s, std::vector<std::string> &dictionary)
    {
        int n = s.length();
        std::unordered_set<std::string> dict(dictionary.begin(), dictionary.end());
        std::vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            dp[i] = dp[i - 1] + 1;

            for (int j = i - 1; j >= 0; j--)
            {
                std::string word = s.substr(j, i - j);

                if (dict.count(word) > 0)
                {
                    dp[i] = std::min(dp[i], dp[j]); 
                }
            }
        }

        return dp[n];
    }
};