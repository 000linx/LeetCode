#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int countPairs(std::vector<int> &nums, int target)
    {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                if(nums[i] + nums[j] < target)
                    ans++;
            }
        }
            return ans;
    }
};