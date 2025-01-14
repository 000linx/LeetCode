#include <iostream>
#include <unordered_map>
#include <vector>

class Solution
{
public:
    const int Mod = 1e9 + 7;
    int firstDayBeenInAllRooms(std::vector<int> &nextVisit)
    {
        int n = nextVisit.size();
        std::vector<long long> v(n);
        for (int i = 0; i < n; i++)
        {
            int j = nextVisit[i];
            v[i + 1] = (v[i] * 2 - v[j] + 2 + Mod) % Mod;
        }
        return v[n - 1];
    }
};

int main()
{
    std::vector<int> v = {0, 1, 2, 0};
    Solution s;
    s.firstDayBeenInAllRooms(v);
    return 0;
}