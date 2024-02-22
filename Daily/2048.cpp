#include <iostream>
#include <vector>
#include <algorithm>
class Solution
{
public:
    bool check(int temp){
        std::vector<int> v(10);
        while (temp != 0)
        {
            v[temp % 10]++;
            temp /= 10;
        }
        for (int j = 0; j < 10; j++)
        {
            if (v[j] > 0 && v[j] != j)
            {
                return false;
            }
        }
        return true;
    }
    int nextBeautifulNumber(int n)
    {
        std::vector<int> v(10);
        for (int i = n + 1; i <= 1224444;i++){
           if(check(i))
               return i;
        }
        return -1;
    }
};

int main(){
    Solution s;
    int n = 1332;
    std::cout << s.nextBeautifulNumber(n);
    return 0;
}