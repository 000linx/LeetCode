#include <iostream>
#include <vector>

class Solution
{
public:
    std::string dayOfTheWeek(int day, int month, int year){
        std::vector<std::string> v = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        if(month < 3){
            year -= 1;
            month += 12;
        }
        int w = 365 * year + year / 4 - year / 100 + year / 400 + (153 * month - 457) / 5 + day - 306;
        w = (w % 7 + 7) % 7;
        return v[w];
    }
};
