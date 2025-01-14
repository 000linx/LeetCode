#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

/*哈希表*/

class Solution
{
public:
    std::vector<int> distinctDifferenceArray(std::vector<int> &nums)
    {
        int n = nums.size();
        std::vector<int> suf(n + 1);
        std::vector<int> ans(n);
        std::unordered_set<int> st;
        for (int i = n - 1; i >= 0; i--){
            st.insert(nums[i]);
            suf[i] = st.size();
        }
        st.clear();
        for (int i = 0; i < n; i++){
            st.insert(nums[i]);
            ans[i] = st.size() - suf[i + 1];
        }
        return ans;
    }
    
};

int main(){

    Solution s;
    std::vector<int> v = {3, 2, 3, 4, 2};
    s.distinctDifferenceArray(v);
    return 0;
}