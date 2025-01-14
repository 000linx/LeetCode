#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

/*模拟*/
class Solution
{
public:
    int hIndex(std::vector<int> &citations)
    {
        int ans = 0, n = citations.size() - 1;
        while (ans >= 0 && citations[n] > ans)
        {
            ans++;
            n--;
            if(n < 0)
                break;
        }
        return ans;
    }
};

int main()
{

    Solution s;
    std::vector<int> v = {1};
    s.hIndex(v);
    return 0;
}