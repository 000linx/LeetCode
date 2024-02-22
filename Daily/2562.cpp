#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>

class Solution
{
    using ll = long long;
public:
    long long findTheArrayConcVal(std::vector<int> &nums)
    {
        ll ans = 0;
        while(!nums.empty())
        {
            int n = nums.size();
            if(n == 1)
            {
                ans += nums[0];
                nums.erase(nums.begin());
            }
            else{
                std::string begin = std::to_string(nums[0]), end = std::to_string(nums[n - 1]);
                std::string sum = begin + end;
                ans += std::stoi(sum);
                nums.erase(nums.begin());
                nums.erase(nums.end() - 1);
            }
        
        }
        return ans;
    }
};

int main()
{
    Solution s;
    std::vector<int> v = {5, 14, 13, 8, 12};
    s.findTheArrayConcVal(v);
    return 0;
}