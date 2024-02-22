#include <iostream>
#include <algorithm>
#include <vector>

/*模拟*/

class Solution
{
public:
    int maximumNumberOfStringPairs(std::vector<std::string> &words)
    {
        int n = words.size();
        int ans = 0;
        for (int i = 0; i < n; i++){
            std::string s = words[i];
            std::reverse(s.begin(), s.end());
            for (int j = i + 1; j < n; j++){
                if(words[j] == s)
                    ans++;
            }   
        }
        return ans;
    }
};