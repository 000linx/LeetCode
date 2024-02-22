#include <iostream>
#include <vector>
#include <math.h>
#include <numeric>


/*模拟*/
class Solution
{
public:
    int minOperationsMaxProfit(std::vector<int> &customers, int boardingCost, int runningCost)
    {
        int ans = -1;
        int Max = 0, temp = 0;
        int wait = 0, i = 0;
        while(wait|| i < customers.size()){
            wait += i < customers.size() ? customers[i] : 0;
            int sum = std::min(wait, 4);
            wait -= sum;
            temp += sum * boardingCost - runningCost;
            i++;
            if(temp > Max){
                ans = i;
                Max = temp;
            }
        }
        return ans;
    }

};

int main(){
    Solution s;
    std::vector<int> v = {8, 3};
    s.minOperationsMaxProfit(v, 5, 6);
    return 0;
}