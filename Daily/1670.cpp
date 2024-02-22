#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

class FrontMiddleBackQueue
{
public:
    std::deque<int> l;
    std::deque<int> r;
    FrontMiddleBackQueue()
    {

    }

    void pushFront(int val)
    {
        l.push_front(val);
        if(l.size() == r.size() + 2){
            r.push_front(l.back());
            l.pop_back();
        }
    }

    void pushMiddle(int val)
    {
        if(l.size() + 1 == r.size()){
            r.push_front(l.back());
            l.pop_back();
        }
        l.push_back(val);
    }

    void pushBack(int val)
    {
        r.push_back(val);
        if(l.size() + 1 == r.size()){
            l.push_back(r.front());
            r.pop_front();
        }
    }

    int popFront()
    {
        if(l.empty()){
            return -1;
        }
        int val = l.front();
        l.pop_front();
        if(l.size() + 1 == r.size()){
            l.push_back(r.front());
            r.pop_front();
        }
        return val;
    }

    int popMiddle()
    {
        if (l.empty())
        {
            return -1;
        }
        int val = l.back();
        l.pop_back();
        if(l.size() + 1 == r.size()){
            l.push_back(r.front());
            r.pop_front();
        }
        return val;
    }

    int popBack()
    {
        if (l.empty())
        {
            return -1;
        }
        int val = 0;
        if(r.empty()){
            val = l.back();
            l.pop_back();
        }
        else{
            val = r.back();
            r.pop_back();
            if (l.size() == r.size() + 2)
            {
                r.push_front(l.back());
                l.pop_back();
            }
        }
        return val;
    }
};
