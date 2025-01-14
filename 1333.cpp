#include<iostream>
#include<vector>
#include<algorithm>

class Solution
{
public:
    // bool cmp(std::vector<int> &x,std::vector<int> &y){
    //         if(x[1]==y[1])
    //             return x[0] > y[0];
    //         else
    //             return x[1] > y[1];
    // }
    std::vector<int> filterRestaurants(std::vector<std::vector<int>> &restaurants, int veganFriendly, int maxPrice, int maxDistance)
    {
        std::vector<std::vector<int>> ans;
        for (int i = 0; i < restaurants.size();i++)
        {
            if ((veganFriendly == 0 || (veganFriendly == 1 && restaurants[i][2] == 1)) && restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance)
            {
                ans.push_back(restaurants[i]);
            }
       }
       sort(ans.begin(),ans.end(),[](std::vector<int> x,std::vector<int> y)->bool{
        if(x[1] == y[1])
        {
            return x[0] > y[0];
        }
        else
            return x[1] > y[1];
       });
       std::vector<int> v;
       for(auto x: ans)
       {
            v.push_back(x[0]);
       }
       return v;
    }
};