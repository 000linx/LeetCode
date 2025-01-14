#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

class Solution
{
public:
    std::vector<int> successfulPairs(std::vector<int> &spells, std::vector<int> &potions, long long success)
    {
        sort(potions.begin(), potions.end());
        int n = spells.size(), m = potions.size();
        std::vector<int> ans(n,0);
        for (int i = 0; i < n; i++)
        {
            int l = 0, r = m;
            while(l < r)
            {
                int mid = (l + r) / 2;
                if((long long)spells[i] * potions[mid] >= success)
                    r = mid;
                else
                    l = mid + 1;
            }
            ans[i] = m - r;
        }
        return ans;
    }
};

int main(){

    Solution s;
    std::vector<int> v = {5, 1, 3};
    std::vector<int> v1 = {1, 2, 3, 4, 5};
    long long success = 7;
    s.successfulPairs(v, v1, success);
    return 0;
}