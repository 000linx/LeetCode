#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
class Solution
{
public:
    int firstCompleteIndex(std::vector<int> &arr, std::vector<std::vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        std::unordered_map<int, std::pair<int, int>> M;
        std::vector<int> row(n, 0);
        std::vector<int> col(m, 0);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                M[mat[i][j]] = {i, j};
            }
        }

        for (int i = 0; i < arr.size();i++){
            auto &t = M[arr[i]];
            row[t.first]++;
            if(row[t.first] == m){
                return i;
            }
            col[t.second]++;
            if(col[t.second] == n){
                return i;
            }
        }

        return -1;
    }
};