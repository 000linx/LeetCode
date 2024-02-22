#include <iostream>
#include <vector>
#include <functional>
/*深度优先搜索 + 贪心*/
class Solution
{
public:
    long long minimumFuelCost(std::vector<std::vector<int>> &roads, int seats)
    {
        int n = roads.size();
        if(n == 0)
            return 0;
        std::vector<std::vector<int>> v(n + 10);
        for(auto &i:roads){
            int x = i[0],y = i[1];
            v[x].push_back(y);
            v[y].push_back(x);
        }
        long long ans = 0;
        std::function<int(int, int)> dfs = [&](int city, int far) -> int
        {
            int sum = 1;
            for(auto neighbor :v[city]){
                if(neighbor != far){
                    int cnt = dfs(neighbor, city);
                    sum += cnt;
                    ans += (cnt + seats - 1) / seats;
                }
            }
            return sum;
        };
        dfs(0, -1);
        return ans;
     }
};

int main(){
    Solution s;
    std::vector<std::vector<int>> v={{3,1},{3,2},{1,0},{0,4},{0,5},{4,6}};
    int seat = 2;
    s.minimumFuelCost(v, seat);
    return 0;
}