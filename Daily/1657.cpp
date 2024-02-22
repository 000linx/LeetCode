#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

class Solution
{
public:
    bool closeStrings(std::string word1, std::string word2)
    {

        std::map<char, int,std::greater<int>> m1;
        std::map<char, int,std::greater<int>> m2;
        
        if(word1.length() != word2.length())
            return false;
        for (int i = 0; i < word1.length(); i++)
        {
            if (word2.find(word1[i]) == std::string::npos)
            {
                return false;
            }
        }
        for (int i = 0; i < word1.length();i++){
            m1[word1[i]]++;
            m2[word2[i]]++;
        }
        int i = 0;
        std::vector<int> v1(m1.size());
        std::vector<int> v2(m2.size());
        for (auto it1 = m1.begin(), it2 = m2.begin(); it1 != m1.end();it1++,it2++,i++){
            v1[i] = it1->second;
            v2[i] = it2->second;
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        for (int i = 0; i < v1.size(); i++){
            if(v1[i] != v2[i]){
                return false;
            }
        }
            return true;
    }
};


int main(){
    std::string s1 = "abbbzcf";
    std::string s2 = "babzzcz";
    Solution s;
    s.closeStrings(s1, s2);
}