#include <iostream>
#include <vector>
#include <algorithm>


/*二分查找*/

class Solution
{
public:
    int maxNumberOfAlloys(int n, int k, int budget, std::vector<std::vector<int>> &composition, std::vector<int> &stock, std::vector<int> &cost)
    {
        int left = 1, right = 2e8, ans = 0;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            bool ok = false;
            for (int i = 0; i < k; i++){
                long long sum = 0;
                for (int j = 0; j < n; j++){
                    sum += std::max(static_cast<long long>(composition[i][j]) * mid - stock[j], 0LL) * cost[j];
                }
                if(sum <= budget){
                    ok = true;
                    break;
                }
            }
            if(ok){
                ans = mid;
                left = mid - 1;
            }
            else{
                right = mid - 1;
            }
        }
        return ans;
    }
};