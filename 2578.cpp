#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

class Solution
{
public:
    int splitNum(int num)
    {
        std::vector<int> v;
        while(num > 0)
        {
            int n = num % 10;
            v.push_back(n);
            num /= 10;
        }
        sort(v.begin(), v.end());
        int a = 0,b = 0;
        for (int i = 0; i < v.size(); i += 2)
        {
            a = a*10 + v[i];
            if(i + 1 < v.size())
            b = b * 10 + v[i + 1];
        }
        int ans = a + b;
        return ans;
    }
};

int main()
{
    Solution s;
    std::cout << s.splitNum(4325);
    return 0;
}