#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

/*单调栈*/

class Solution
{
public:
    std::vector<int> canSeePersonsCount(std::vector<int> &heights)
    {
        int n = heights.size();
        std::vector<int> ans(n);
        std::stack<int> s;
        for (int i = n- 1; i >= 0; i--){
            while(!s.empty() && heights[i] > s.top()){
                s.pop();
                ans[i]++;
            }
            if(!s.empty()){
                ans[i]++;
            }
            s.push(heights[i]);
        }

        return ans;
    }
};

int main(){
    Solution s;
    std::vector<int> v = {10, 6, 8, 5, 11, 9};
    s.canSeePersonsCount(v);
    return 0;
}