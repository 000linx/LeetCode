#include <iostream>
#include <algorithm>
#include <vector>

class Solution
{
public:
    int minLength(std::string s)
    {
        std::vector<std::string> v = {"AB", "CD"};
        bool ok = false;
        while(!ok){
            if (s.find(v[0]) != std::string::npos)
            {
                int pos = s.find(v[0]);
                s.erase(pos, 2);
            }
            else if (s.find(v[1]) != std::string::npos)
            {
                int pos = s.find(v[1]);
                s.erase(pos, 2);
            }
            else{
                ok = true;
            }
        }
        return s.size();
    }
};