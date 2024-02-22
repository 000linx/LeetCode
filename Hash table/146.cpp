#include<iostream>
#include<vector>
#include<iterator>
#include<unordered_map>
/*
哈希表加双向链表 
哈希表用于实现快速查找，双向链表用于实现插入删除
LRU缓存机制
双向连链表按使用的顺序储存，越靠近头部代表越先使用的，越靠近尾部代表越后使用
哈希表，通过键值来映射在双向链表里的位置

*/
class Node
{
    public:
        int k, v;
        Node *pre;
        Node *next;
        Node() : k(0), v(0), pre(nullptr), next(nullptr){};
        Node(int key, int value) : k(key), v(value), pre(nullptr), next(nullptr){};
};

class LRUCache
{
    std::unordered_map<int, Node *> LRU;
    int size;
    Node *tail;
    void Delete(Node *node)
    {
        node->pre->next = node->next;
        node->next->pre = node->pre;

    }
    void addHead(Node *node)
    {
        node->pre = tail;
        node->next = tail->next;
        node->pre->next = node;
        node->next->pre = node;
    }

public:
    LRUCache(int capacity):size(capacity),tail(new Node())
    {
        tail->pre = tail;
        tail->next = tail;
    }

    int get(int key)
    {
        auto ok = LRU.find(key);
        if(ok != LRU.end())
        {
            auto node = ok->second;
            Delete(node);
            addHead(node);
            return node->v;
        }
        return -1;
        }

    void put(int key, int value)
    {
        int check = get(key);
        auto node = LRU.find(key)->second;
        if(check != -1)
        {
            node->v = value;
            return;
        }
        LRU[key] = node = new Node(key, value);
        addHead(node);
        if(LRU.size() > size)
        {
            auto last = tail->pre;
            LRU.erase(last->k);
            Delete(last);
            delete last;
        }
    }
};