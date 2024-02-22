#include <iostream>
#include <vector>
#include <queue>

/*数学 + 中位数贪心 + 对顶堆*/
class Solution
{
public:
    const int Mod = 1e9 + 7;
    std::vector<int> numsGame(std::vector<int> &nums)
    {
        int n = nums.size();
        long long l_sum = 0, r_sum = 0;
        std::vector<int> ans(n,0);
        std::priority_queue<int> left;
        std::priority_queue<int, std::vector<int>, std::greater<int>> right;

        for (int i = 0; i < n; i++){
            int b = nums[i] - i;
            if(i %2 == 0){
                if(!left.empty() && b < left.top()){
                    l_sum -= left.top() - b;
                    left.push(b);
                    b = left.top();
                    left.pop();
                }
                r_sum += b;
                right.push(b);
                ans[i] = (r_sum - right.top() - l_sum) % Mod;
            } else {
                if(b > right.top()){
                    r_sum += b - right.top();
                    right.push(b);
                    b = right.top();
                    right.pop();
                }
                l_sum += b;
                left.push(b);
                ans[i] = (r_sum - l_sum) % Mod;
            }
        }
        return ans;
    }
};