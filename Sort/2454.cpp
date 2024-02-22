#include <iostream>
#include <vector>
#include <set>
#include <algorithm>


/*排序加有序集合*/
class Solution
{
public:
    std::vector<int> secondGreaterElement(std::vector<int> &nums)
    {
        int n = nums.size();
        std::vector<int> ans(n,-1);
        std::vector<std::pair<int, int>> p(n);
        for (int i = 0; i < n; i++){
            p[i] = {-nums[i], i};
        }
        sort(p.begin(), p.end());
        std::set<int> s;
        for(auto &[_,i]:p){
            auto it = s.upper_bound(i);
            if(it != s.end() && s.upper_bound(*it) != s.end()){
                auto temp = s.upper_bound(*it);
                ans[i] = nums[*temp];
            }
            s.insert(i);
        }
        return ans;
    }
};