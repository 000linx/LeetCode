#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    std::string maximumOddBinaryNumber(std::string s)
    {
        int n = s.length();
        int sum = 0;
        for (int i = 0; i < n; i++){
            if(s[i] == '1')
                sum++;
        }
        sum -= 1;
        std::string ans;
        for (int i = 0; i < n - 1; i++){
            if(sum){
                ans += '1';
                sum--;
            }
            else {
                ans += '0';
            }
        }
        return ans += '1';

        
    }
};