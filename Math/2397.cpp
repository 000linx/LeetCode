#include <iostream>
#include <cstring>
#include <vector>

/*二进制位运算*/
class Solution
{
public:
    int maximumRows(std::vector<std::vector<int>> &matrix, int numSelect)
    {
        int n = matrix[0].size(), m = matrix.size();
        int row[m];
        std::memset(row, 0, sizeof(row));

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if(matrix[i][j])
                    row[i] |= 1 << j;
            }
        }
        
        int ans = 0;
        for (int i = 1; i < 1 << n;i++){
            if (__builtin_popcount(i) != numSelect)
                continue;
            int j = 0;
            for(int x:row){
                j += (x & i) == x;
            }
            ans = std::max(ans, j);
        }
        return ans;
    }
};