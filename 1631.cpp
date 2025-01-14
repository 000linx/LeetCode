#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
class Solution
{
public:
    int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int minimumEffortPath(std::vector<std::vector<int>> &heights)
    {
        int n = heights[0].size();
        int m = heights.size();
        int Max = 1e7;
        std::vector<std::vector<int>> v(m,std::vector<int>(n,Max));
        v[0][0] = 0;
        std::queue<int> q;
        q.push(0);
        while(!q.empty()){
            int top = q.front();
            q.pop();
            int x = top / n;
            int y = top % n;
            for (int i = 0; i < 4; i++){
                int next_x = x + dir[i][0];
                int next_y = y + dir[i][1];
                if(next_x >= 0 && next_y >=0 && next_x < m && next_y < n){
                    int t = std::max(v[x][y],std::abs(heights[next_x][next_y] - heights[x][y]));
                    if(t > v[next_x][next_y]){
                        continue;
                    }
                    v[next_x][next_y] = t;
                    q.push(next_x * n + next_y);
                }
            }
        }
        return v[m - 1][n - 1];
    }
};