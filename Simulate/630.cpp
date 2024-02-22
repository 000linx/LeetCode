#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

/*反悔贪心*/
class Solution {
public:
    int scheduleCourse(std::vector<std::vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[](const auto &a,const auto &b){return a[1] < b[1];});
        std::priority_queue<int>q;
        int sum = 0;
        for(auto &x:courses){
            int dur = x[0],last = x[1];
            if( sum + dur <= last){
                sum+=dur;
                q.push(dur);
            }
            else if(!q.empty() && q.top() > dur){
                sum -= q.top() - dur;
                q.pop();
                q.push(dur);
            }
        }
        return q.size();
    }
};  