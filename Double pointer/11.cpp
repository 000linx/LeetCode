#include <iostream>
#include <vector>
#include <algorithm>

/*双指针*/
class Solution
{
public:
    int maxArea(std::vector<int> &height)
    {
        int ans = 0;
        int l = 0, r = height.size() - 1;
        while(l < r){
            int area = (r - l) * std::min(height[l], height[r]);
            ans = std::max(ans, area);
            if(height[l] < height[r])
                l += 1;
            else
                r -= 1;
            
        }
        return ans;
    }
};