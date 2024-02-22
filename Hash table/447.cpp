#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_map>

/*哈希表加遍历*/
class Solution
{
public:
    int numberOfBoomerangs(std::vector<std::vector<int>> &points)
    {
        int ans = 0;
        std::unordered_map<int, int> m;
        for(auto i:points){
            m.clear();
            for(auto j: points){
                int distance = pow(i[0] - j[0], 2) + pow(i[1] - j[1], 2);
                ans += m[distance] * 2;
                m[distance]++;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    std::vector<std::vector<int>>v = {{1,1},{2,2},{3,3}};
    s.numberOfBoomerangs(v);
    return 0;
}