#include<iostream>

class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans = 0;
        for(int i = 0; i*cost1 <= total ; ++i){
            ans += (total - i*cost1)/cost2 + 1;
        }
        return ans;
    }
};

int main(){
    Solution s;
    std::cout << s.waysToBuyPensPencils(5,10,10);
}