#include<iostream>
#include<vector>
#include<math.h>
#include<queue>
#include<algorithm>
/*拓扑排序*/
class Solution {
public:
    std::vector<int>findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        std::vector<std::vector<int>>v(numCourses);
        std::vector<int>indeg(numCourses);
        for(auto& i:prerequisites){
            int x = i[0],y = i[1];
            v[y].push_back(x);
            ++indeg[x];
        }
        std::queue<int>q;
        for(int i = 0; i < numCourses ;i++){
              if(indeg[i] == 0)q.push(i);
        }
        std::vector<int>ans;
              while(!q.empty()){
                int top = q.front();
                q.pop();
                ans.push_back(top);
                for(int i :v[top]){
                    if(--indeg[i] == 0)q.push(i);
                }

              }
        if(ans.size() != numCourses )return {};
        return ans;
    }
};