#include <iostream>
#include <algorithm>
#include <vector>


/*数学 + 模拟*/
class Solution
{
public:
    long long minimumRemoval(std::vector<int> &beans)
    {
        sort(beans.begin(), beans.end());
        long long sum = 0,Max = 0;
        for (int i = 0; i < beans.size(); i++){
            sum += beans[i];
            Max = std::max(Max, (long long)(beans.size() - i) * beans[i]);
        }
        return sum - Max;
    }
};