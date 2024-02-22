#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

/*递归
根据题目要求，i * i 的十进制表示的字符串可以分割成若干连续子字符串，且这些子字符串对应的整数值之和等于 i
那么就是先把 i^2用to_string转为字符串，对这个字符串s进行判断
对于字符串s而言，now_pos表示当前的位置，now_sum表示当前的和，target表示目标值即i
用递归的方法，从s[0]开始,即now_pos = 0 ,now_sum = 0进行判断
遍历这个字符串,循环变量i = now_pos从而保证不重复遍历
我们用sum表示在这个递归中的和是多少
如果sum + now_sum > target，即表示当前的sum + 之前的sum和超过目标值，即可以退出循环
当now_pos = s.size()时我们需要判断now_sum是否等于target,从而判断是否符合条件


*/
class Solution
{
public:
    bool check(std::string &now, int now_pos,int now_sum,int target)
    {
        int sum = 0;
        if(now_pos == now.size())
            return now_sum = target ? true:false;
        for (int i = now_pos; i < now.size();i++)
        {
            sum = sum * 10 + now[i] - '0';
            if(sum + now_sum> target)
                break;
            if(check(now,i + 1,sum + now_sum,target))
                return true;
        }
        return false;
    }
    int punishmentNumber(int n)
    {
        int ans = 0;
        for (int i = 1; i <= n;i++)
        {
            std::string s = std::to_string(i * i);
            bool ok = check(s,0,0,i);
            if(ok)
                ans += i * i;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    s.punishmentNumber(10);
    return  0;
}