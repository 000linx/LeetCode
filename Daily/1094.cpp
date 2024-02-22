#include <iostream>
#include <vector>
#include <algorithm>
/*差分数组*/
class Solution
{
public:
    bool carPooling(std::vector<std::vector<int>> &trips, int capacity)
    {
        //第一步创建一个差分数组
        int n = trips.size();
        std::vector<int> v(1010);

        //第二步进行差分
        for (int i = 0; i < n; i++){
            v[trips[i][1]] += trips[i][0];
            v[trips[i][2]] -= trips[i][0];
        }

        //第三步,进行还原,这里还原出来的是到达i时车上的人数。
        int sum = 0;
        for(int number:v){
            sum += number;
            //在还原的时候我们判断sum是否会超过capacity的
            if(sum > capacity)
                return false;
        }
        return true;
    }

};