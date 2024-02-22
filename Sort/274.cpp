#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>

/*排序*/
//至少发布了H篇文章，并且每篇文章的引用次数是大于等于H的
class Solution
{
public:
    int hIndex(std::vector<int> &citations)
    {
        int ans = 0,n = citations.size() - 1;
        sort(citations.begin(), citations.end());
        while(ans >= 0 && citations[n] > ans)
        {
            ans++;
            n--;
        }
        return ans;
    }
};

int main()
{

    Solution s;
    std::vector<int> v = {1,3,1};
    s.hIndex(v);
    return 0;
}