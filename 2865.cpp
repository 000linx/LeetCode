#include <iostream>
#include <vector>

/*模拟*/

class Solution
{
public:
    long long maximumSumOfHeights(std::vector<int> &maxHeights)
    {
        int n = maxHeights.size();
        long long ans = 0;
        for (int i = 0; i < n; i++){
            int pre = maxHeights[i];
            long long sum = pre;
            //山峰左边
            for (int j = i - 1; j > 0; j--){
                pre = std::min(pre, maxHeights[j]);
                sum += pre;
            }
            int suf = maxHeights[i];
            //山峰右边
            for (int j = i + 1; j < n; j++){
                suf = std::min(suf, maxHeights[j]);
                sum += suf;
            }
            ans = std::max(ans, sum);
        }
        return ans;
    }
};