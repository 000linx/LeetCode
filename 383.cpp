#include <iostream>
#include <algorithm>


/*哈希表*/

class Solution
{
public:
    bool canConstruct(std::string ransomNote, std::string magazine)
    {
        int arr[26]{};
        for(char &c : magazine){
            arr[c - 'a']++;
        }
        for(char &c: ransomNote){
            if(--arr[c -'a'] < 0){
                return false;
            }
        }
        return true;
    }
};

