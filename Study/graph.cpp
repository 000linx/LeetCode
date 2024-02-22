#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int sumNode = 8;//假设我们有七个节点
    vector<vector<int>> Graph(sumNode);//二维数组用于构建图

    //建图,这里我们手动输入
    Graph[3].push_back(10);
    Graph[3].push_back(8);
    Graph[5].push_back(11);
    Graph[7].push_back(11);
    Graph[7].push_back(8);
    Graph[8].push_back(9);
    Graph[11].push_back(2);
    Graph[11].push_back(10);
    Graph[11].push_back(9);

    
        return 0;
}