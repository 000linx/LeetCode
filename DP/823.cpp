#include<iostream>
#include<vector>
#include<math.h>
#include<unordered_set>
#include<functional>

/*动态规划*/
class Solution {
public:
    int numFactoredBinaryTrees(std::vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        std::unordered_set<int>m(arr.begin(),arr.end());
        std::vector<long long>memo(n,-1);

        std::function<long long (int)>dfs = [&](int val) ->long long {
            long long &res = memo[val];
            if(res != -1)return res;
            res = 1;
            int temp = arr[val];
            for(int i = 0; i < val ;i++){
                int x = arr[i];
                if(temp%x == 0 && m.count(temp/x)){
                    res += dfs(x)*dfs(temp/x);
                }
            }
            return res;
        };
        long long ans = 0;
        for(int i = 0 ;i < n ;i++){
            ans += dfs(i);
        }
        return ans%MOD;
    }
};