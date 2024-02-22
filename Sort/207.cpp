#include<iostream>
#include<vector>
#include<math.h>
#include<queue>
#include<algorithm>


//思路为拓扑排序
/*
拓扑排序是有向无环图的排序
给定一个包含 n 个节点的有向图 G，我们给出它的节点编号的一种排列，如果满足：
对于图 G 中的任意一条有向边 (u,v)，u 在排列中都出现在 v 的前面。那么就是称为拓扑排序
*/

/*
我们将入度为0的节点都放入队列中，在广度优先搜索中，我们取出队首的节点u:
1.我们将u放入答案中
2.我们移除u的所有出边，也就是将u所有相邻节点的入度都减少1如果相邻节点v的入度为0
那么我们将v放入队列中

在广搜结束后，如果答案中包含了n这个节点，那么我们就得到了一种拓扑排序

*/
class Solution {
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        std::vector<std::vector<int>>v(numCourses);
        std::vector<int>edge(numCourses);
        for(auto& i:prerequisites){
            int x = i[0],y = i[1];
            v[y].push_back(x);
            ++edge[x];
        }
        std::queue<int>q;
        for(int i = 0; i < numCourses ;i++){
              if(edge[i] == 0)q.push(i);
        }
        int visited = 0;
              while(!q.empty()){
                int top = q.front();
                q.pop();
                visited++;
                for(int i :v[top]){
                    if(--edge[i] == 0)q.push(i);
                }

              }
        return visited == numCourses;

    }
};