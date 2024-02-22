#include <iostream>
#include <vector>


/*回文串简单模拟*/
class Solution
{
public:
    std::string makeSmallestPalindrome(std::string s)
    {
        int n = s.size();
        for (int i = 0,j = n - 1; i < n / 2 && i!= j;i++,j--){
            if(s[i] == s[j])
                continue;
            if(s[i] > s[j]){
                s[i] = s[j];
            }
            else {
                s[j] = s[i];
            }
        }
        return s;
    }
};

int main(){
    Solution sou;
    std::string s = "abcd";
    sou.makeSmallestPalindrome(s);
}