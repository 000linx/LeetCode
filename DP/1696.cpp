#include <iostream>
#include <vector>
#include <queue>

/*动态规划 + 单调栈*/
class Solution
{
public:
    int maxResult(std::vector<int> &nums, int k)
    {
        int n = nums.size();
        std::vector<int> v(n);
        v[0] = nums[0];
        std::deque<int> q = {0};

        for (int i = 1; i < n; i++){
            if(q.front() < i - k){
                q.pop_front();
            }

            v[i] = v[q.front()] + nums[i];
            while( !q.empty() && v[i] >= v[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }
        return v[n - 1];
    }
};