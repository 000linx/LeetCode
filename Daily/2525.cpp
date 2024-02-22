#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <math.h>

class Solution
{
public:
    std::string categorizeBox(int length, int width, int height, int mass)
    {
        bool Bulky = false, Heavy = false;
        long long m = std::max(length, std::max(width, height));
        long long v = 1L * length * width * height;
        if (m >= 10000 || v >= 1000000000){
            Bulky = true;
        }
        if(mass >= 100){
            Heavy = true;
        }
        if(Bulky && Heavy)
        {
            return "Both";
        }
        else if(!Bulky && Heavy){
            return "Heavy";
        }
        else if(Bulky && !Heavy){
            return "Bulky";
        }
        else{
            return "Neither";
        }
    }
};