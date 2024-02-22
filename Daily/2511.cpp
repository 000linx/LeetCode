#include<iostream>
#include<vector>
#include<math.h>
class Solution {
public:
    int captureForts(std::vector<int>& forts) {
       int ans = 0,sum = 0;
       for(int i = 0 ;i < forts.size() ;){
        int j = i + 1;
        if(forts[i]!=0){
            while(j < forts.size() && forts[j] == 0)++j;
            if(j < forts.size() && forts[i] + forts[j] == 0)ans = std::max(ans,j- i -1);
        }
        i = j;
       }
       return ans;
    }
};

int main(){
    Solution s;
    std::vector<int>v(5);
    for(int i = 0; i < v.size();i++){
        std::cin >> v[i];
    }
    std::cout << s.captureForts(v);
}