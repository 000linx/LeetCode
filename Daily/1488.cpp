#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>
#include <unordered_map>

class Solution
{
public:
    std::vector<int> avoidFlood(std::vector<int> &rains)
    {
        std::unordered_map<int, int> m;
        int n = rains.size();
        std::vector<int> ans(n);
        if (n == 0)
        {
            return ans;
        }
        for (int i = 0; i < n; i++)
        {
            m[rains[i]]++;
            if(rains[i]==0)
                ans[i] = 0;
            else
                ans[i] = rains[i];
        }
        
        for (int i = 1; i < n; i++)
        {
            
            if (rains[i]!=0 && rains[i] != rains[i - 1])
            {
                if(m[rains[i]] == 1)
                    ans[i] = -1;
                if (m[rains[i]] > 1 && m[0] > 0)
                {
                    m[0]--;
                    m[rains[i]]--;
                    ans[i] = -1;
                    auto index = find(ans.begin(), ans.end(), 0);
                    if(index!=ans.end())
                    {
                        ans[*index] = rains[i];
                    }
                }
                else if (m[rains[i]] > 1 && m[0] <= 0)
                    return ans={};

            }
            else
                return ans = {};
        }
        for (int i = 0; i < ans.size();i++)
        if(ans[i]==0)
                ans[i] = 1;
            return ans;
    }
};


int main(){

    Solution s;
    std::vector<int> v = {69, 0, 0, 0, 69};
    return 0;
}