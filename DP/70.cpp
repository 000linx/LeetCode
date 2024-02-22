#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
/*
动态规划
对于n级台阶需要多少步则需要考虑到n - 1和n - 2需要多少步
即f(n) = f(n - 1) + f(n - 2)
当n = 0时只有一种方案，当n = 1时也只有一种方案
当n = 2时f(2) = f(1) + f(0)即两种方案
当n = 3是f(3) = f(2) + f(1)即三种方案
*/
class Solution
{
public:
    int climbStairs(int n)
    {
        int fn = 1, f1 = 0, f2 = 0;
        for (int i = 1; i <= n;i++)
        {
            f1 = f2;
            f2 = fn;
            fn = f1 + f2;
        }

        return fn;
    }
};