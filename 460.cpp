#include<iostream>
#include<unordered_map>
#include<set>
#include<utility>
struct Node
{
    int k, v,c,t;//c是使用频率，t是使用时间
    Node(int key, int value, int cnt, int time) : k(key), v(value), c(cnt), t(time){}

    //比较函数，用于比较在相同的频率下使用时间最后的那一个
    bool operator<(const Node& use) const {
        return c == use.c ? t < use.t : c < use.c;
    }
};
class LFUCache
{
    int size, time;
    std::set<Node> s;
    std::unordered_map<int, Node> LFR;
public:
    LFUCache(int capacity)
    {
        size = capacity;
        time = 0;
        s.clear();
        LFR.clear();
    }

    int get(int key)
    {
        if (size == 0)
            return -1;
        auto it = LFR.find(key);
        if (it == LFR.end())
            return -1;
        Node cache = it->second;
        s.erase(cache);
        cache.c += 1;
        cache.t = ++time;
        s.insert(cache);
        it->second = cache;
        return cache.v;
    }

    void put(int key, int value)
    {   
        if(size == 0)
            return;
        auto node = LFR.find(key);
        if(node == LFR.end())
        {
            if(size == LFR.size())
            {
                //容量满的使用删除最后的那个
                LFR.erase(s.begin()->k);
                s.erase(s.begin());
            }
            //创建一个新的缓存，将这个缓存存入哈希表和平衡二叉树中
            Node cache = Node(key, value, 1, ++time);
            LFR.insert(std::make_pair(key,cache));
            s.insert(cache);
        }
        else
        {
            //这个键值已经存在，那么就更新它的value，并且频率加一，时间加一
            Node cache = node->second;
            s.erase(cache);
            cache.c += 1;
            cache.t = ++time;
            cache.v = value;
            s.insert(cache);
            node->second = cache;
        }
    }
};