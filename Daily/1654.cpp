#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>
#include<map>
#include<tuple>
class Solution {
    std::vector<int>vis;
    int ans = 100100;
public:
    void dfs( int x,int a,int b,int count,int back){
        if(x == 0){
            ans = std::min(ans,count);
            return ;
        }
        if(x - a >= 0 && vis[x - a] != 1){
            vis[x -a] = 1;
            dfs(x -a,a,b,count + 1,0); 
        }
        if(x + b < 6001 && vis[x + b] != 1 && back == 0){
            vis[x + b] = 1;
            dfs(x + b ,a, b,count + 1,1);
            vis[x + b] = 0;
        }

    }
    
    int minimumJumps(std::vector<int>& forbidden, int a, int b, int x) {
    vis.resize(10010,0);
    for(int i = 0; i < forbidden.size() ;i++){
        vis[forbidden[i]] = 1;
    }
    dfs(x,a,b,0,0);
    if(ans < 100010)return ans;
    else return -1;
    }

};