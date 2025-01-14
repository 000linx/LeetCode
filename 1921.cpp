#include<iostream>
#include<vector>
#include<algorithm>
class Solution {
public:
    int eliminateMaximum(std::vector<int>& dist, std::vector<int>& speed) {
        int n = dist.size();
        std::vector<int>v;
        for(int i = 0; i <n ;i++)v.push_back((dist[i] - 1) / speed[i]);
        sort(v.begin(),v.end());

        for(int i = 0 ;i < n ; i++){
            if(v[i] < i)return i;
        }

        return n;

    }
};