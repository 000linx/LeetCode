#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <unordered_map>

/*哈希表*/
class Solution
{
public:
    std::vector<std::string> findRepeatedDnaSequences(std::string s)
    {
        int cnt = 10;
        std::vector<std::string> ans;
        std::unordered_map<std::string, int> m;
        int n = s.size();
        for (int i = 0; i <= n - cnt; i++)
        {
            std::string str = s.substr(i, cnt);
            if(++m[str] == 2)
                ans.push_back(str);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    std::string str = "A";
    s.findRepeatedDnaSequences(str);
    return 0;
}
