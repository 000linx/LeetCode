#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <math.h>

class Solution
{
public:
    int tupleSameProduct(std::vector<int> &nums)
    {
        std::unordered_map<int, int> m;
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int sum = nums[i] * nums[j];
                m[sum]++;
                
            }
        }
        for (const auto &i:m)
        {
            ans += (i.second * (i.second - 1)) / 2;
        }
            return ans * 8;
    }
};

int main(){
    Solution s;
    std::vector<int> v = {2, 3, 4, 6, 8, 12};
    s.tupleSameProduct(v);
    return 0;
}