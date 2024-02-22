#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

class Solution {
public:
    std::vector<bool> checkIfPrerequisite(int numCourses, std::vector<std::vector<int>>& prerequisites, std::vector<std::vector<int>>& queries) {
        std::vector<bool>ans;
        std::vector<std::vector<int>>v(numCourses);
        std::vector<int>indeg(numCourses);
        for(auto& i:prerequisites){
            int x = i[0],y = i[1];
            v[x].push_back(y);
            ++indeg[y];
        }
        std::queue<int>q;
        std::vector<std::vector<bool>>bo(numCourses,std::vector<bool>(numCourses,false));   
        for(int i = 0; i < numCourses ;i++){
              if(indeg[i] == 0)q.push(i);
        }
        while(!q.empty()){
            auto a = q.front();
            q.pop();
            for(int i :v[a]){
                bo[a][i] = true;
                for(int j = 0;j < numCourses ; j++){
                bo[j][i] = bo[j][i] | bo[j][a];

            }
            if(--indeg[i] == 0)q.push(i);
            }
        }
        for(auto &qu :queries){
            ans.push_back(bo[qu[0]][qu[1]]);
        }
        return ans;
    }
};