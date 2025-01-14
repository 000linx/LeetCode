#include <iostream>
#include <vector>

/*遍历*/
class Solution
{
public:
    int maximumSwap(int num)
    {
        std::string s = std::to_string(num);
        int n = s.length();
        int index = n - 1;
        int x = -1, y;
        for (int i = n - 2; i >= 0; i--){
            if(s[i] > s[index]){
                index = i;
            }else if(s[i] < s[index]){
                x = i;
                y = index;
            }
        }
        if(x == -1)
            return num;
        else
            std::swap(s[x], s[y]);
        return std::stoi(s);
    }
}
;