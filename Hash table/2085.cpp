#include <iostream>
#include <vector>
#include <unordered_map>

/*哈希表*/
class Solution
{
public:
    int countWords(std::vector<std::string> &words1, std::vector<std::string> &words2)
    {
        int ans = 0;
        std::unordered_map<std::string, int> w1,w2;
        for(auto s:words1){
            w1[s]++;
        }
        for(auto s:words2){
            w2[s]++;
        }
        for(auto s:words1){
            if(w1[s] == 1 && w2[s] == 1)
                ans++;
        }
        
        return ans;
    }
};

int main(){
    Solution s;
    std::vector<std::string> w1 = {"leetcode", "is", "amazing", "as", "is"};
    std::vector<std::string> w2 = {"amazing", "leetcode", "is"};
    s.countWords(w1, w2);
    return 0;
}