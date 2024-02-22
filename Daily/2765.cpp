#include <iostream>
#include <vector>


/*分组循环*/
class Solution
{
public:
    int alternatingSubarray(std::vector<int> &nums)
    {
        int ans = -1;
        int n = nums.size(), i = 0;
        while(i < n - 1){
            if(nums[i + 1] - nums[i] != 1){
                i++;
                continue;
            }
            int index = i;
            i += 2;
            while(i < n && nums[i] == nums[index] + (i - index) % 2){
                i++;
            }
            ans = std::max(ans, i - index);
            i--;
        }
        return ans;
    }
};