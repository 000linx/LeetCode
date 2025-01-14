#include <iostream>
#include <vector>
#include <algorithm>

/*双指针*/
class Solution
{
public:
    int trap(std::vector<int> &height)
    {
        int ans = 0;
        int l = 0, r = height.size() - 1;
        int pre_sum = 0, suf_sum = 0;
        while(l <= r){
            pre_sum = std::max(pre_sum, height[l]);
            suf_sum = std::max(suf_sum, height[r]);
            if(pre_sum < suf_sum){
                ans += pre_sum - height[l];
                l += 1;
            }
            else{
                ans += suf_sum - height[r];
                r -= 1;
            }
        }
        return ans;
    }
};
