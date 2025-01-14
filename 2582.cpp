#include<iostream>
#include<vector>


class Solution
{
public:
    int passThePillow(int n, int time)
    {
        int i = 1;
        bool ok = false;
        while(time--)
        {
            if(!ok)
            {
                i++;
                if(i == n)
                    ok = true;
            }
            else{
                i--;
                if(i == 1)
                    ok = false;
            }
        }
        return i;
    }
};

int main()
{
    Solution s;
    std::cout << s.passThePillow(4, 5);

    return 0;
}