#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int minDeletion(std::vector<int> &nums)
    {
        int ans = 0;
        int n = nums.size();
        if(n == 0)
            return 0;
        for (int i = 0; i < n; i++)
            if (nums[i] == nums[i + 1] && i + 1 < n && (i - ans) %2 == 0)
                ans++;
       if((n -ans)%2 != 0)
           ans++;
        return ans;
    }
};

int main(){
    Solution s;
    std::vector<int> v = {1, 1, 2, 2, 3, 3};
    s.minDeletion(v);

    return 0;
}