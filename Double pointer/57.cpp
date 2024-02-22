
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>

/*双指针，插入区间，方法与合并区间类似*/
class Solution {
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
        intervals.push_back({newInterval});
        std::vector<std::vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        for(int i = 0; i < n ;){
            int t = intervals[i][1];
            int j = i + 1;
            while(j < n && intervals[j][0] <= t){
                t = std::max(intervals[j][1],t);
                j++;
            }
            ans.push_back({intervals[i][0],t});
            i = j;
        }
        return ans;

    }
};