#include <iostream>
#include <vector>
#include <array>
#include <functional>


/*动态规划*/
class Solution
{
public:
    int findRotateSteps(std::string ring, std::string key)
    {
        int n = ring.length(), m = key.length();

        std::array<int, 26> pos;
        for (int i = 0; i < n; i++){
            ring[i] -= 'a';
            pos[ring[i]] = i;
        }

        std::vector<std::array<int, 26>> left(n);
        std::vector<std::array<int, 26>> right(n);
        for (int i = 0; i < n; i++){
            left[i] = pos;
            pos[ring[i]] = i;
        }

        for (int i = n - 1; i >= 0; i--){
            pos[ring[i]] = i;
        }

        for (int i = n - 1; i >= 0; i--){
            right[i] = pos;
            pos[ring[i]] = i;
        }

        std::vector<std::vector<int>> memo(m, std::vector<int>(n, -1));
        std::function<int(int, int)> dfs = [&](int j, int i) -> int {
                if(j == m){
                    return 0;
                }
                int &res = memo[j][i];
                if(res != -1){
                    return res;
                }

                char c = key[j] - 'a';
                if(ring[i] == c){
                    return res = dfs(j + 1, i);
                }
                int l = left[i][c], r = right[i][c];
                return res = std::min(dfs(j + 1, l) + (l > i ? n - l + i : i - l),
                                 dfs(j + 1, r) + (r < i ? n - i + r : r - i));
        };
        int ans = dfs(0, 0) + m;
        return ans;
    }
};

int main(){
    Solution s;
    std::string str1 = "godding";
    std::string str2 = "gd";
    s.findRotateSteps(str1, str2);
    return 0;
}