#include<iostream>
#include<vector>
#include<algorithm>

class Solution
{
public:
    std::vector<std::vector<int>> queensAttacktheKing(std::vector<std::vector<int>> &queens, std::vector<int> &king)
    {
        std::vector<std::vector<int>> v;
        bool visited[8][8];
        int d[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        for(auto &x:queens){
            visited[x[0]][x[1]] = true;
        }
        for(auto &i:d){
            int x = king[0] + i[0];
            int y = king[1] + i[1];
            while(x < 8 && x >= 0 && y < 8 && y >= 0){
                if(visited[x][y]){
                    v.push_back({x, y});
                    break;
                }
                x += i[0];
                y += i[1];
            }
        }
        return v;
    }

};