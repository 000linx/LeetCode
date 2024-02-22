#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <unordered_map>

/*并查集*/
class Solution
{
public:
    int g(std::vector<int> &v, int x)
    {
        if (v[x] == x)
            return x;
        int nv = g(v, v[x]);
        v[x] = nv;
        return nv;
    }
    int minSwapsCouples(std::vector<int> &row)
    {
        int n = row.size();
        int m = n / 2;
        std::vector<int> v(m,0);
        std::unordered_map<int, int> M;
        for (int i = 0; i < m; i++)
            v[i] = i;
        auto a = [&](std::vector<int> &v, int x, int y)
        {
            int vx = g(v, x);
            int vy = g(v, y);
            v[vx] = vy;
        };
        for (int i = 0; i < n; i += 2)
        {
            int l = row[i] / 2;
            int r = row[i + 1] / 2;
            a(v, l, r);
        }
        for (int i = 0; i < m; i++)
        {
            int vx = g(v, i);
            M[vx]++;
        }
        int ans = 0;
        for(const auto& [v,sz]:M)
        {
            ans += sz - 1;
        }
        return ans;
    } 
};

int main(){
    Solution s;
    std::vector<int> v = {4, 6, 1, 3, 5, 7, 12, 13, 15, 11, 0, 10, 2, 8, 9, 14};
    s.minSwapsCouples(v);
    return 0;
}