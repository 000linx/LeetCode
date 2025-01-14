#include <iostream>
#include <vector>

/*快速幂*/

class Solution
{
public:
    const int MOD = 1e9 + 7;
    long long quick_M(long long a, int b)
    {
        a %= MOD;
        long long res = 1;
        while (b)
        {
            if (b & 1)
            {
                res = res * a % MOD;
            }
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }
    int minNonZeroProduct(int p)
    {
        long long ans = (1LL << p) - 1;
        long long res = (ans - 1, p - 1) % MOD;
        return ans % MOD * res;
    }
};