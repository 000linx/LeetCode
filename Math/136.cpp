#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>

/*位运算*/
class Solution
{
public:
    int singleNumber(std::vector<int> &nums)
    {
        int ans;
        std::map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }
        for (int i = 0; i < nums.size();i++)
        {
            if(m[nums[i]] == 1)
            {
                ans = nums[i];
                break;
            }
        }
            return ans;
    }
};

int main()
{
    Solution s;
    std::vector<int> v = {2, 2, 1};
    s.singleNumber(v);
    return 0;
}