#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>


/*
动态规划

先选择满意度小的再选择满意度大的
对于第i次选择，我们可以选择做第j道菜，也可以选择不做第j道菜
设v[i][j]表示为在已经选了前i道菜之后，选择j道菜的最大喜欢程度，并且i>=j，那么对于第i道菜的选择
1.选择第i道菜，那么他的最大值就是在前i - 1道菜的喜欢值和加上了第i道菜之后的喜欢值中取最大值
v[i][j] = max(v[i][j],v[i-1][j - 1] + i * satisfaction[i])
2.不选择第i道菜，那么他的最大值就是，前i - 1道菜中选择第j道菜的喜欢值
v[i][j] = max(v[i][j],v[i - 1][j])

所以v[i][j] = max(v[i - 1][j],v[i - 1][j - 1] + i * satisfaction[i])
*/
class Solution
{
public:
    int maxSatisfaction(std::vector<int> &satisfaction)
    {
        int n = satisfaction.size();
        int ans = 0;
        std::vector<std::vector<int>> v(n + 1, std::vector<int>(n + 1));
        sort(satisfaction.begin(), satisfaction.end());
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i;j++)
            {
                v[i][j] = v[i - 1][j - 1] + satisfaction[i - 1] * j;
                if(i > j)   
                {
                    v[i][j] = std::max(v[i - 1][j], v[i][j]);

                }
                ans = std::max(ans, v[i][j]);
            }
        }
        return ans;
    }
};


int main()
{

    Solution s;
    std::vector<int> v = {4, 3, 2};
    s.maxSatisfaction(v);
    return 0;
}