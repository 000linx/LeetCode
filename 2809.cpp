#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstring>
#include <numeric>

/*动态规划 + 排序*/
class Solution
{
public:
    int minimumTime(std::vector<int> &nums1, std::vector<int> &nums2, int x)
    {
        int n = nums1.size();
        std::vector<std::pair<int, int>> v;
        for (int i = 0; i < n; i++){
            v.emplace_back(nums2[i], nums1[i]);
        }
        sort(v.begin(), v.end());
        int dp[n + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++){
            for (int j = 0; j <= n; j++){
                dp[i][j] = dp[i - 1][j];
                if(j){
                    auto[x, y] = v[i - 1];
                    dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1] + y + x * j);
                }
            }
        }
        int sum1 = std::accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = std::accumulate(nums2.begin(), nums2.end(), 0);
        for (int i = 0; i <= n; i++){
            if(sum1 + sum2 * i - dp[n][i] <= x){
                return i;
            }
        }
        return -1;
    }
};