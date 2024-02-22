#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>
#include <map>

/*哈希表*/
class Solution
{
public:
    std::vector<int> singleNumber(std::vector<int> &nums)
    {
        std::vector<int> ans;
        std::map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (m[nums[i]] == 1)
            {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};