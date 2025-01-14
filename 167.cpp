#include <iostream>
#include <vector>
#include <algorithm>

/*双指针*/
class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &numbers, int target)
    {
        std::vector<int> ans;
        int l = 0, r = numbers.size() - 1;
        while(l <r){
            if(numbers[l] + numbers[r] == target)
            break;
            if (numbers[l] + numbers[r] > target)
                r -= 1;
            if (numbers[l] + numbers[r] < target)
                l += 1;
        }
        ans.push_back(l + 1);
        ans.push_back(r + 1);
        return ans;
    }
};