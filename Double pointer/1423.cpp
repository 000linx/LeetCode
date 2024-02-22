#include <iostream>
#include <vector>
#include <algorithm>
/*
双指针，滑动窗口
每次行动都是从队首或者队尾取一张卡,在取k次过后剩下的一定是连续的数组
那么剩下的越小，就说明我们取的越大。
求最小和的子数组
数组的长度为n,那么n - k就是我们要求的子数组的长度，记作m
先求出前m个数的和记作sum，再不断更新sum的值

*/
class Solution
{
public:
    int maxScore(std::vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        int m = n - k;
        int sum = 0;
        for (int i = 0; i < m;i++){
            sum += cardPoints[i];
        }
            int ans = sum;
        for (int i = m; i < n; i++){
            sum += cardPoints[i] - cardPoints[i - m];
            ans = std::min(ans, sum);
        }
        int sum1 = 0;
        for(auto x : cardPoints)
            sum1 += x;
        return sum1 - ans;
    }
};

int main(){
    Solution s;
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;
    s.maxScore(v,k);
}