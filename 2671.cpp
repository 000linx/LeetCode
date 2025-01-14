#include <iostream>
#include <vector>
#include <unordered_map>

class FrequencyTracker
{
    std::unordered_map<int, int> m; // 存每个number出现的次数
    std::unordered_map<int, int> n; // 存出现次数的次数，比如1出现了一次，或者1出现了两次
public:
    FrequencyTracker()
    {
    }

    void add(int number)
    {
        --n[m[number]];
        m[number]++;
        n[m[number]]++;
    }

    void deleteOne(int number)
    {
        if (!m[number])
        {
            return;
        }
        --n[m[number]];
        ++n[--m[number]];
    }

    bool hasFrequency(int frequency)
    {
        return n[frequency];
    }
};