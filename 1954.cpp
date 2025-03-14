#include <iostream>
#include <math.h>

class Solution
{
public:
    long long minimumPerimeter(long long neededApples)
    {
        long long n = std::cbrt(neededApples / 4.0);
        if (2 * n * (n + 1) * (2 * n + 1) < neededApples)
        {
            n++;
        }
        return 8 * n;
    }
};
