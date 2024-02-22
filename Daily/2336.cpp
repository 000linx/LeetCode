#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

class SmallestInfiniteSet
{
public:
    int val = 1;
    std::set<int> s;
    SmallestInfiniteSet()
    {
    }

    int popSmallest()
    {
        if(s.empty()){
            int num = val;
            val++;
            return num;
        }
        int num = *s.begin();
        s.erase(s.begin());
        return num;
    }

    void addBack(int num)
    {
       if(num < val)
           s.insert(num);
    }
};