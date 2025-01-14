#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int longestAlternatingSubarray(std::vector<int> &nums, int threshold)
    {
        int ans = 0, n = nums.size(), i = 0;
        while(i < n){
            if(nums[i] % 2 != 0 || nums[i] > threshold)
            {
                i++;
                continue;
            }
            int s = i;
            i++;
            while(i < n && nums[i] <= threshold && nums[i] % 2 != nums[i - 1] % 2)
            {
                i++;
            }
            ans = std::max(ans, i - s);
        }
        return ans;
    }
};


int main(){

    Solution s;
    std::vector<int> v = {3, 2, 5, 4};
    int n = 5;
    s.longestAlternatingSubarray(v, n);
    return 0;
}