#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    long long countFairPairs(std::vector<int> &nums, int lower, int upper)
    {
        int n = nums.size();
        long long sum = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            auto target = std::lower_bound(nums.begin(), nums.begin() + i, lower - nums[i]);
            auto target1 = std::upper_bound(nums.begin(), nums.begin() + i, upper - nums[i]);
            sum += target1 - target;
        }
        return sum;
    }
};

int main(){
    Solution s;
    std::vector<int> v = {1, 7, 9, 2, 5};
    int l = 11, r = 11;
    s.countFairPairs(v, l, r);
    return 0;
}