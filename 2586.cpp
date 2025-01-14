#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <unordered_set>

class Solution
{
public:
    int vowelStrings(std::vector<std::string> &words, int left, int right)
    {
        int ans = 0;
        int n = words.size();
        std::unordered_set<char> s;
        s.insert('a');
        s.insert('e');
        s.insert('i');
        s.insert('o');
        s.insert('u');
        for (int i = left; i <= right; i++)
        {
            int x = words[i].size();
            char top = words[i][0], end = words[i][x - 1];
            if(s.find(top)!= s.end() && s.find(end) != s.end())
                ans++;
        }
            return ans;
    }
};