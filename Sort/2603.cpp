#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<math.h>

/*
一.将一个点的邻居个数作为它的度数，如果这个点的度数为1，那么这个节点就是叶子节点，
如果这个叶子节点上没有金币，那么可以去掉这个叶子节点。去掉之后可能会有新的叶子节点，
没有金币就继续去掉。
拓扑排序实现
将没有金币的叶子节点加入队列中，然后开始循环，直到队列为空。每次循环将首节点x出队列,
然后将它相邻的点的度数减一，如果这个点的度数为一且没有金币，那么就将这个点加入队列。

二.由于题目要求是最后回到出发点，那么无论从那个点出发每条边都会走两次。即将出发点作为根
递归遍历这个树，往下递是一次，往上归是一次，所以答案是剩余边数*2


*/
class Solution
{
public:
    int collectTheCoins(std::vector<int> &coins, std::vector<std::vector<int>> &edges)
    {
        int n = coins.size();
        std::vector<int> v(n);//用于记录点的度数
        std::vector<std::vector<int>> Map(n);//用于构建图
        for(auto &x: edges)
        {
            int i = x[0], j = x[1];
            Map[i].push_back(j);
            Map[j].push_back(i);
            //统计点的度数，因为是无向图所以两个点都要算度数
            v[i]++;
            v[j]++;
        }

        int ans = n - 1;
        //第一次拓扑排序，去掉所有没有金币的子树
        std::vector<int> vec;//用作队列
        for(int i = 0; i < n; i ++)
        {
            if(v[i] == 1 && coins[i] == 0)//当前节点度数为1，且没有金币
            //将这个点加入队列中
                vec.push_back(i);
        }
        while(!vec.empty())
        {
            ans--;//删除到其父节点的边
            int x = vec.back();
            vec.pop_back();
            for(int i: Map[x])
            {
                if (--v[i] == 1 && coins[i] == 0) // 如果当前节点度数为1，且没有金币，将该节点加入队列
                    vec.push_back(i);

            }
        }
        //第一次拓扑排序完后，队列为空
        //第二次拓扑队列，用于统计度数为1，且有金币的节点
        for (int i = 0; i < n; i++)
        {
            if(v[i] == 1 && coins[i] == 1)//有金币的点
                vec.push_back(i);
        }
        ans -= vec.size();//删除所有到其父节点的边
        for (int x : vec)//遍历所有的点
        {
            for (int y : Map[x])
            {
                if (--v[y] == 1)
                    ans--;//删除y到其父节点的边
            }
        }
        return std::max(ans * 2, 0);
    }
};