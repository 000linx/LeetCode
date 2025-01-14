#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
/*双指针，合并区间*/
class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());//首先对数组进行排序
        std::vector<std::vector<int>>ans;
        for(int i = 0 ; i < intervals.size() ;){
            int t = intervals[i][1];//右指针为第一个区间的最后一个元素
            int j = i + 1;
            //开始判断，当下一个区间的第一个元素是小于或者等于t的时候，就说明两个区间有重合的部分
            while(j < intervals.size() && intervals[j][0] <= t){
                //此时进行更新右指针为两个区间的最后一个元素中大的那一个
                t = std::max(intervals[j][1],t);
                j++;
            }
            ans.push_back({intervals[i][0],t});
            i = j;
        }
        return ans;
    }
};