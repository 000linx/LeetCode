#include <iostream>

/*脑筋急转弯*/
class Solution
{
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity)
    {
        if(jug1Capacity + jug2Capacity < targetCapacity){
            return false;
        }

        int Min = std::min(jug1Capacity, jug2Capacity);
        int Max = std::max(jug1Capacity, jug2Capacity);

        int now = Min + Max;
        while(now){
            if(now == targetCapacity){
                return true;
            }

            if(now >= Min){
                now -= Min;
            }else{
                now += Max;
            }
        }
        return false;
    }

};