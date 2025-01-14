#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>


class Solution {
public:
    bool checkValidGrid(std::vector<std::vector<int>>& grid) {
    int dx[] = {2,2,-2,-2,1,-1,1,-1};
    int dy[] = {1,-1,1,-1,2,2,-2,-2}; 
    int n = grid.size();
    if(grid[0][0]!=0)return false;
    int tx = 0,ty = 0;
    int i = 0,xx,yy;
    while(i < n*n - 1){
        bool ok = true;
        for(int j = 0;j < 8 && ok ;j++){
            xx = tx + dx[j];
            yy = ty + dy[j];
            if(xx >= 0 && xx < n && yy >= 0 && yy < n && grid[xx][yy] == i+1){
                ok = false;
                break;
            }
        }
        if(ok)return false;
        tx = xx,ty = yy,i++;
    }
    return true;
    }
};