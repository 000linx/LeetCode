#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    int minimumSeconds(std::vector<int> &nums)
    {
        std::unordered_map<int, std::vector<int>> index;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            index[nums[i]].push_back(i);
        }

        int ans = n + 1;
        for(auto &pos : index){
            auto &it = pos.second;
            int time = 0;
            it.emplace_back(it[0] + n);
            for (int i = 1; i < it.size(); i++){
                time = std::max(time, (it[i] - it[i - 1]) / 2);
            }
            ans = std::min(ans, time);
        }
        return ans;
    }
};
