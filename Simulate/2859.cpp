#include <iostream>
#include <vector>
#include <algorithm>

/*模拟*/
class Solution
{
public:
    int sumIndicesWithKSetBits(std::vector<int> &nums, int k)
    {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            int temp = i, cnt = 0;
            while(temp != 0){
                cnt += (temp % 2);
                temp /= 2;
            }
            if(cnt == k){
                ans += nums[i];
            }
        }
        return ans;
    }
};