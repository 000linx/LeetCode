#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
    int indexOfMax(std::vector<int> &a)
    {
        return max_element(a.begin(), a.end()) - a.begin();
    }

     public : std::vector<int> findPeakGrid(std::vector<std::vector<int>> &mat)
    {
        int left = 0, right = mat.size() - 1;
        while (left < right)
        {
            int i = left + (right - left) / 2;
            int j = indexOfMax(mat[i]);
            if (mat[i][j] > mat[i + 1][j])
            {
                right = i; 
            }
            else
            {
                left = i + 1; 
            }
        }
        return {left, indexOfMax(mat[left])};
    }
};