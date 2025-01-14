#include<iostream>
#include<vector>

class LockingTree
{
    std::vector<int> father;
    std::vector<int> LockNodeUser;
    std::vector<std::vector<int>> children;

public:
    bool FatherNodeIsLock(int num)
    {
        num = father[num];
        while(num!=-1)
        {
            if(LockNodeUser[num] != -1)//判断父节点是否上锁
            {
                return true;
            }
            num = father[num];
        }
        return false;
    }
    bool ChildrenNodeIsLock(int num)
    {
        bool check = LockNodeUser[num] != -1;//判断当前节点是否上锁
        LockNodeUser[num] = -1;//将当前节点上锁
        for(int ch :children[num])
        {
            check |= ChildrenNodeIsLock(ch);
        }
        return check;
    }
    LockingTree(std::vector<int> &parent)
    {
        int n = parent.size();
        this->father = father;
        this->LockNodeUser = std::vector<int>(n, -1);
        this->children = std::vector<std::vector<int>>(n);
        for (int i = 0; i < n; i ++)
        {
          if(parent[i] != -1)
          {
                children[parent[i]].emplace_back(i);
          }
        }
    }

    bool lock(int num, int user)
    {
        if(LockNodeUser[num] == -1)//节点未上锁
        {
            LockNodeUser[num] = user;
            return true;
        }
        return false;
    }

    bool unlock(int num, int user)
    {
        if(LockNodeUser[num] == user)//节点是当前这个用户上锁的
        {
            LockNodeUser[num] = -1;
            return true;
        }
        return false;
    }

    bool upgrade(int num, int user)
    {
        bool check = false;
        if (LockNodeUser[num] == -1 && !FatherNodeIsLock(num) && ChildrenNodeIsLock(num))
        {
            check = true;
            LockNodeUser[num] = user; // 为当前节点上锁
        }
        return check;
    }
};