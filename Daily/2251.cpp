#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
class Solution
{
public:
    std::vector<int> fullBloomFlowers(std::vector<std::vector<int>> &flowers, std::vector<int> &people)
    {
        int n = flowers.size();
        std::vector<int> s(n), e(n);
        std::vector<int> answer;
        for (int i = 0; i < n; i++)
        {
            s.push_back(flowers[i][0]);
            e.push_back(flowers[i][1]);
        }
        sort(s.begin(), s.end());
        sort(e.begin(), e.end());
        for(int &i:people)
        {
            i = (std::upper_bound(s.begin(), s.end(), i) - s.begin()) - (std::lower_bound(e.begin(), e.end(), i) - e.begin());
            answer.push_back(i);
            
        }
        return answer;
    }
};