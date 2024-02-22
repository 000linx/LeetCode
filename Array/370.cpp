#include <iostream>
#include <vector>
/*差分数组*/
class Solution
{
public:
    std::vector<int> getModifiedArray(int length, std::vector<std::vector<int>> &updates)
    {
        //定义一个ans用于记录结果，diff_array用作差分数组
        std::vector<int>ans(length,0);
        std::vector<int> diff_array(length+10);
        //让diff_array[0] = ans[0]就表示我们将ans[0],补在了差分数组的开头
        diff_array[0] = ans[0];
        //第一步先求一下差分数组，这题其实可以不写,因为初始的数组全是0
        for (int i = 1; i < length;i++)
            diff_array[i] = ans[i] - ans[i - 1];
        
        //第二步进行数组的修改
        for (int i = 0; i < updates.size();i++){
            //updata[i][0]代表修改的起点，updata[i][1] + 1代表要修改的终点，updata[i][2]代表要修改的值
            diff_array[updates[i][0]] += updates[i][2];
            diff_array[updates[i][1] + 1] -= updates[i][2];
        }

        //第三步,通过差分数组还原初始数组
        ans[0] = diff_array[0];
        for (int i = 1; i < length;i++){
            ans[i] += diff_array[i] + ans[i - 1];
        }
        return ans;
    }
};