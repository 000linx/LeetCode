#include<iostream>
#include<math.h>

class Solution
{
public:
    int distMoney(int money, int children)
    {
        if(money < children)
           return -1;
        if(money > 8 * children)
           return children - 1;
        if(money == 8 * children - 4)
           return children - 2;
           
        return (money - children) / 7;
    }
};