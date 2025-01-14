#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
//只统计出现一次的字符，如果这个子串中所有的字符出现的次数都大于1，则countUniqueChar(t) = 0
/*
哈希表
对于这个字符串中的每一个字符，它可能在不同的子串中被统计到，我们需要统计这个字符能够作为唯一值的子串有
多少个，即为这个字符的贡献是多少，然后计算总的贡献


*/
class Solution
{
public:

    int uniqueLetterString(std::string s)
    {
        std::vector<std::vector<int>> index(26,{-1});
        int ans = 0, n = s.length();
        for (int i = 0; i < n; i++){
            index[s[i] - 'A'].push_back(i);
        }
        for(auto &v :index){
            v.push_back(s.length());
            for (int i = 1; i < v.size() - 1; ++i){
                ans += (v[i] - v[i - 1]) * (v[i + 1] - v[i]);
            }
        }
        return ans;
    }
};

int main(){
    Solution v;
    std::string s = "ABC";
    v.uniqueLetterString(s);

    return 0;
}