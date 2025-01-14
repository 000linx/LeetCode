#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

/*暴力模拟*/
class Solution
{
public:
    int romanToInt(std::string s)
    {
        std::unordered_map<char, int> M;
        M['I'] = 1;
        M['V'] = 5;
        M['X'] = 10;
        M['L'] = 50;
        M['C'] = 100;
        M['D'] = 500;
        M['M'] = 1000;
        int ans = 0;
        for (int i = s.length() - 1; i>=0 ; i--){
           if(i == 0)
               ans += M[s[0]];
            else{
                if(M[s[i]] > M[s[i - 1]]){
                    ans += M[s[i]] - M[s[i - 1]];
                    i--;
                }
                else
                    ans += M[s[i]];
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    std::string L = "MCMXCIV";
    s.romanToInt(L);
    return 0;
}