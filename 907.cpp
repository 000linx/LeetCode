#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
/*
求以 arr[i] 为最小值的子数组的个数。
对于 arr[i] 我们找出其左边第一个小于 arr[i] 的位置 left[i].
右侧第一个小于等于 arr[i]的位置 right[i].
则以 arr[i]为最小值的子数组的个数为 (i−left[i])×(right[i]−i)
3 1 2 4
对于下标为0，元素值为3来说
从左边开始找，发现没有小于3的因为3的左边是没有数字的，初始化为-1
从右边开始找，发现第一个小于3的值是2，下标为2
那么包含3并且是以3为最小值的子数组的个数就是(0 - (-1)) * (2 - 0) = 2 即{3}和{3,4}


*/
class Solution
{
public:
    const int Mod = 1e9 + 9;
    int sumSubarrayMins(std::vector<int> &arr)
    {
        long long ans = 0;
        int n = arr.size();
        std::vector<int> left(n,-1), right(n,n);
        std::stack<int> ls,rs;
        for (int i = 0; i < n; i++){
            while(!ls.empty() && arr[i] <= arr[ls.top()]){
                ls.pop();
            }
            if(!ls.empty()){
                left[i] = ls.top();
            }
            ls.push(i);
        }
        for (int i = n - 1; i >= 0; i--){
            while(!rs.empty() && arr[i] < arr[rs.top()]){
                rs.pop();
            }
            if (!rs.empty())
            {
                right[i] = rs.top();
            }
            rs.push(i);
        }

        for (int i = 0; i < n; i++){
            ans += (long long ) ((i - left[i])* (right[i] - i) * arr[i]) % Mod;
        }
        return ans;
    }
};


int main(){
    Solution s;
    std::vector<int> v = {3, 1, 2, 4};
    s.sumSubarrayMins(v);
    return 0;
}
