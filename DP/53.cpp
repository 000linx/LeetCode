#include <iostream>
#include <vector>
#include <algorithm>
/*
动态规划
定义状态
ans[i]:表示为以nums[i]结尾的连续子数组的最大和

转移方程
对于nums[i],我们是一定要取到的，那么对于nums[i]结尾和nums[i - 1]结尾的子数组之间就相差一个nums[i]
1.nums[i - 1] > 0
ans[i] = ans[i - 1] + nums[i];
2.nums[i - 1] < 0
ans[i] = nums[i];

初值
当只有一个数的时候，ans[0] = nums[0]


std::vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
*/

class Solution
{
public:
    int maxSubArray(std::vector<int> &nums)
    {
        int n = nums.size();
        std::vector<int> ans(n);
        ans[0] = nums[0];
        for (int i = 1; i < n; i++){
            if(ans[i - 1] > 0){
                ans[i] = ans[i - 1] + nums[i];
            }
            else {
                ans[i] = nums[i];
            }
        }

        int sum = ans[0];
        for (int i = 1; i < n; i++){
            sum = std::max(sum, ans[i]);
        }
        return sum;
    }
};

int main(){
    Solution s;
    std::vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    s.maxSubArray(v);

    return 0;
}