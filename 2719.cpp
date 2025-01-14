#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
/*数位dp*/

class Solution
{
public:
    const int mod = 1e9 + 7;
    int calcu(std::string s, int min_sum, int max_sum){
        int n = s.length();
        std::vector<std::vector<int>> memory(n, std::vector<int>(std::min(n * 9, max_sum) + 1, -1));
        std::function<int(int, int, bool)> dfs = [&](int i, int sum, bool limit) -> int {
            if(sum > max_sum){
                return 0;
            }
            if(i == n){
                return sum >= min_sum ? 1 : 0;
            }
            if(!limit && memory[i][sum] != -1){
                return memory[i][sum];
            }

            int temp = limit ? s[i] - '0' : 9;
            int res = 0;
            for (int j = 0; j <= temp; j++){
                res = (res + dfs(i + 1, sum + j, limit && j == temp)) % mod;
            }
            if(!limit){
                memory[i][sum] = res;
            }
            return res;
        };
        return dfs(0, 0, true);
    }
    int count(std::string num1, std::string num2, int min_sum, int max_sum)
    {
        int ans = calcu(num2, min_sum, max_sum) - calcu(num1, min_sum, max_sum) + mod;
        int sum = 0;
        for(char c : num1){
            sum += c - '0';
        }
        ans += min_sum <= sum && sum <= max_sum;
        return ans % mod;
    }
};