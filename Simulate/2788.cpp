#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>


/*模拟*/
class Solution
{
public:
    std::vector<std::string> splitWordsBySeparator(std::vector<std::string> &words, char separator)
    {
        std::vector<std::string> ans;
        for(std::string s:words){
            while(s.find(separator) != std::string::npos){
                int index = s.find(separator);
                std::string str = s.substr(0, index);
                if(str != ""){
                    ans.push_back(str);
                }
                s.erase(0, index + 1);
            }
            if(s != ""){
                ans.push_back(s);
            }
        }
       
            return ans;
    }
};

int main(){
    Solution S;
    std::vector<std::string> v = {"|||"};
    S.splitWordsBySeparator(v, '|');
    return 0;
}