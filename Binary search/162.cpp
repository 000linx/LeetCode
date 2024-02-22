#include <iostream>
#include <vector>


/*二分查找*/
class Solution
{
public:
    int findPeakElement(std::vector<int> &nums)
    {
        int left = -1, right = nums.size() - 1; 
        while (left + 1 < right)
        { 
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1])
                right = mid; 
            else
                left = mid; 
        }
        return right;
    }
};