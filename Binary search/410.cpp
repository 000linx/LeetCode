#include <iostream>
#include <vector>

/*二分*/
class Solution
{
public:
    int splitArray(std::vector<int> &nums, int k)
    {
        int ans = nums[0];
        long long t = 0;
        for(int x:nums){
            t += x;
            ans = ans > x ? ans : x;
        }

        while(ans < t){
            long mid = (ans + t) / 2;
            int temp = 0;
            long cnt = 1;
            for(int x: nums){
                temp += x;
                if(temp > mid){
                    temp = x;
                    cnt++;
                }
            }
            if(cnt > k){
                ans = mid + 1;
            }
            else
                t = mid;
        }
        return ans;
    }
};