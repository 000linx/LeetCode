#include<iostream>
#include<vector>

/*贪心遍历*/
class Solution
{
public:
    bool canPlaceFlowers(std::vector<int> &flowerbed, int n)
    {
        bool ok = false;
        flowerbed.push_back(0);
        flowerbed.insert(flowerbed.begin(), 0);
        int m = flowerbed.size();
        for (int i = 1; i + 1 < m; i++ )
        {
            if (flowerbed[i] == 0 && flowerbed[i + 1] == 0 && flowerbed[i - 1] == 0)
            {
                flowerbed[i] = 1;
                n--;
            }         
        }
        if(n <= 0)
            ok = true;
        return ok;
    }
};

int main()
{
    Solution s;
    std::vector<int>v(5);
    for (int i = 0; i < 5; i++)
    {
        std::cin >> v[i];
    }
    s.canPlaceFlowers(v, 1);

    return 0;
}