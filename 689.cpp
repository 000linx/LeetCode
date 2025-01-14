//滑动窗口
#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<int> maxSumOfThreeSubarrays(std::vector<int> &nums, int k)
    {
        std::vector<int> ans;
        int sum1 = 0, maxsum1 = 0,maxsumindex = 0;
        int sum2 = 0, maxsum2 = 0, maxsumindex1 = 0, maxsumindex2 = 0;
        int sum3 = 0, total = 0;
        for (int i = k * 2; i < nums.size();++i){
            sum1 += nums[i - k * 2];
            sum2 += nums[i - k];
            sum3 += nums[i];
            if(i >= k*3 - 1){
                if(sum1 > maxsum1){
                    maxsum1 = sum1;
                    maxsumindex = i - k * 3 + 1;
                }
                if(maxsum1 + sum2 > maxsum2){
                    maxsum2 = maxsum1 + sum2;
                    maxsumindex1 = maxsumindex;
                    maxsumindex2 = i - k * 2 + 1;
                }
                if(maxsum2 + sum3 >total){
                    total = maxsum2 + sum3;
                    ans = {maxsumindex1, maxsumindex2, i - k + 1};
                }
                sum1 -= nums[i - k * 3 + 1];
                sum2 -= nums[i - k * 2 + 1];
                sum3 -= nums[i - k + 1];
            }
        }
        return ans;
    }
};