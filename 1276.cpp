#include <iostream>
#include <vector>
#include <math.h>

class Solution
{
public:
    std::vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices)
    {
        int k = 4 * cheeseSlices - tomatoSlices;
        int y = k / 2;
        int x = cheeseSlices - y;
        return k % 2 || x < 0 || y < 0 ? std::vector<int>{} : std::vector<int>{x, y};
    }
};
