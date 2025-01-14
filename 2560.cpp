#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>


class Solution
{
public:
 
    int minCapability(std::vector<int> &nums, int k)
    {
        int Max = *max_element(nums.begin(), nums.end());
        int Min = *min_element(nums.begin(), nums.end());
        while(Min <= Max)
        {
            int mid = (Min + Max) / 2,count = 0;
            bool ok = false;
            for(auto x: nums)
            {
                if(x <= mid && !ok)
                {
                    count++;
                    ok = true;
                }
                else
                {
                    ok = false;
                }
                if(count >= k)
                    Max = mid - 1;
                else
                    Min = mid + 1;
            }
        }
        return Min;
    }
};

int main(){
    Solution s;
    std::vector<int>v(5);
    for (int i = 0; i < 5;i ++){
        std::cin >> v[i];
    }
    int k;
    std::cin >> k;
    s.minCapability(v, k);
}