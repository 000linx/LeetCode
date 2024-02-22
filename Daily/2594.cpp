#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
class Solution {
public:
    long long repairCars(std::vector<int>& ranks, int cars) {
        int n =  *std::min_element(ranks.begin(),ranks.end());
        long long left = 0,right = cars*cars*1e5*n;
        while(left + 1  < right){
            long long mid = (left + right)/2,sum = 0;
            for(int i = 0 ;i < ranks.size() ;i++)sum+=std::sqrt(mid/ranks[i]);
            if(sum >= cars)right = mid;
            else left = mid;
        }
        return right;
    }   
};