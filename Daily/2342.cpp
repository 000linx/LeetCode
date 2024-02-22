#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <algorithm>

class Solution
{
public:
    int S(int x){
        int sum = 0;
        while(x!=0){
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
    int maximumSum(std::vector<int> &nums)
    {
        int n = nums.size();
        int ans = -1;
        std::vector<std::pair<int, int>> p(nums.size());
        for (int i = 0; i < n; i++)
        {
            p[i].first = nums[i];
            p[i].second = S(nums[i]);
        }
        sort(p.begin(), p.end(), [&](auto &a, auto &b){
            if(a.second == b.second)
                return a.first > b.first;
            return a.second > b.second;
            
            });
        for (int i = n - 1; i > 0; i--){
            if(p[i].second == p[i - 1].second){
                ans = std::max(ans, p[i].first + p[i - 1].first);
            }
        }
            return ans;
    }
};

int main(){
    std::vector<int> v = {18,
                          43,
                          36,
                          13,
                          7};
    Solution s;
    s.maximumSum(v);

    return 0;
}