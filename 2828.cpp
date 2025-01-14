#include <iostream>
#include <vector>

class Solution
{
public:
    bool isAcronym(std::vector<std::string> &words, std::string s)
    {
        std::string ans = "";
        for(auto i:words){
            ans += i[0];
        }
        if(ans != s)
        {
            return false;
        }
        return true;
    }
};