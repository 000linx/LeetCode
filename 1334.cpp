#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    void floyd(std::vector<std::vector<int>> &v){
        int n = v.size();
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                for (int q = 0; q < n; q++){
                    v[j][q] = std::min(v[j][q],v[j][i] + v[i][q] );
                }
            }
        }
    }
    int findTheCity(int n, std::vector<std::vector<int>> &edges, int distanceThreshold)
    {
        std::vector<std::vector<int>> v(n, std::vector<int>(n, 0x3f3f3f3f));
        for (int i = 0; i < n; i++)
            v[i][i] = 0;
        for(const auto& i:edges)
        {
            int a = i[0], b = i[1], c = i[2];
            v[a][b] = v[b][a] = std::min(v[a][b], c);
        }
        floyd(v);
        int ans = -1, cnt = n + 10;
        for (int i = 0; i < n; i++){
            int cur = 0;
            for (int j = 0; j < n; j++){
                if( i != j && v[i][j] <= distanceThreshold)
                    cur++;
            }
            if(cur <= cnt){
                cnt = cur;
                ans = i;
            }
        }
        return ans;
    }
};
