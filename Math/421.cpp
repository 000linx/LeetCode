#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <math.h>

/*位运算*/
class Solution
{
public:
    const int max_high = 30;
    int findMaximumXOR(std::vector<int> &nums)
    {

        int ans = 0;
        for (int i = max_high; i >= 0; --i)
        {
            std::unordered_set<int> s;
            for (auto n:nums)
                s.insert(n >> i);

            bool ok = false;
            int next = ans * 2 + 1;
            
            for(auto n:nums)
            if(s.count(next ^ (n >> i)))
            {
                ok = true;
                break;
            }
            if(ok)
            ans = next;
            else
            ans = next - 1;
        }
        
        return ans;
    }
};


int main()
{

    Solution s;
    std::vector<int> v = {14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70};
    s.findMaximumXOR(v);
    return 0;
}