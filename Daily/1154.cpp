#include <iostream>
#include <vector>

class Solution
{
public:
    int dayOfYear(std::string date)
    {
        int year = (date[0] - '0')*1000 + (date[1] - '0')*100 + (date[2] - '0')*10 +( date[3] - '0');
        int month = (date[5] - '0')*10 + (date[6] - '0');
        int day = (date[8] - '0')*10 + (date[9] - '0');
        std::vector<int> v1 = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        std::vector<int> v2 = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int ans = 0;
        if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
            for (int i = 0; i < month - 1 ;i++){
                ans += v2[i];
            }
            ans += day;
        }
        else {
            for (int i = 0; i < month - 1; i++)
            {
                ans += v1[i];
            }
            ans += day;
        }

        return ans;
    }
};

int main(){
    Solution s;
    std::string s1 = "2019-01-09";
    s.dayOfYear(s1);
    return 0;
}