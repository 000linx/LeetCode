#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
/*二分查找 + 有序集合*/
class RangeModule
{
public:
    int a_max = 0,a_min = 1e9;
    int d_max = 0, d_min = 1e9;
    std::map<int, int> m;
    RangeModule()
    {
        
    }

    void addRange(int left, int right)
    {
        auto it = m.upper_bound(left);
        if(it != m.begin()){
            auto s = prev(it);
            if(s -> second >= right){
                return;
            }
            if(s ->second >= left){
                left = s->first;
                m.erase(s);
            }
        }
        while( it != m.end() && it ->first <= right){
            right = std::max(right, it->second);
            it = m.erase(it);
        }
        m[left] = right;
    }

    bool queryRange(int left, int right)
    {
        auto it = m.upper_bound(left);
        if(it == m.begin()){
            return false;
        }
        it = prev(it);
        return right <= it->second;
    }

    void removeRange(int left, int right)
    {
        auto it = m.upper_bound(left);
        if(it != m.begin()){
            auto s = prev(it);
            if(s -> second >= right){
                int r = s->second;
                if(s ->first == left){
                    m.erase(s);
                }
                else {
                    s->second = left;
                }
                if(right != r){
                    m[right] = r;
                }
                return;
            }
            else if(s ->second > left) {
                if(s->first == left)
                {
                    m.erase(s);
                }
                else {
                    s->second = left;
                }
            }
            
        }
        while (it != m.end() && it->first < right)
        {
            if(it -> second <= right){
                it = m.erase(it);
            }
            else {
                m[right] = it->second;
                m.erase(it);
                break;
            }
        }
        
    }
};