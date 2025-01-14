#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

/*贪心 + 排序*/
class Solution
{
public:
    int stoneGameVI(std::vector<int> &aliceValues, std::vector<int> &bobValues)
    {
        int n = aliceValues.size();
        std::vector<std::pair<int, int>> p(n);
        for (int i = 0; i < n; i++){
            p[i].first = aliceValues[i] + bobValues[i];
            p[i].second = i;
        }
        sort(p.rbegin(), p.rend());
        int ans = 0;
        for (int i = 0; i < n; i++){
            ans += i % 2 == 0 ? aliceValues[p[i].second] : -bobValues[p[i].second];
        }
        ans = (ans > 0) - (ans < 0);
        return ans;
    }
};

int main(){
    Solution s;
    std::vector<int> a = {2, 4, 3};
    std::vector<int> b = {1, 6, 7};
    s.stoneGameVI(a, b);
}