#include <iostream>
#include <vector>

/*双指针 + 贪心*/
class Solution
{
public:
    std::string repeatLimitedString(std::string s, int repeatLimit)
    {
        int n = s.length();
        std::vector<int> v(26);
        for(auto c:s){
            v[c - 'a']++;
        }
        std::string ans;
        int count = 0;
        for (int i = 25, j = 24; i >= 0 && j >= 0;){
            if(v[i] == 0){
                count = 0;
                i--;
            }else if(count < repeatLimit){
                v[i]--;
                ans.push_back(i + 'a');
                count++;
            }else if(v[j] == 0 || j >= i){
                j--;
            }else{
                v[j]--;
                ans.push_back(i + 'a');
                count = 0;
            }
        }
        return ans;
    }
};

int main(){
    Solution s1;
    std::string s = "cczazcc";
    s1.repeatLimitedString(s, 3);
    return 0;
}