#include<iostream>
#include<vector>
#include<algorithm>

class Solution
{
public:
    int giveGem(std::vector<int> &gem, std::vector<std::vector<int>> &operations)
    {
        for( auto &i : operations){
            int x = i[0], y = i[1];
            gem[y] += gem[x] / 2;
            gem[x] -= gem[x] /2;
        }
        sort(gem.begin(), gem.end());
        int n = gem.size();
        return gem[n - 1] - gem[0];
    }
};
int main(){
    Solution s;
    std::vector<int> gem = {100, 0, 50, 100};
    std::vector<std::vector<int>> operations = {{0,2}, {0,1}, {3,0},{3,0}};
    std::cout << s.giveGem(gem, operations);
}