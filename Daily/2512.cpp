#include <iostream>
#include <vector>
#include <algorithm>
#include<set>
class Solution
{
public:
    std::vector<int> topStudents(std::vector<std::string> &positive_feedback, std::vector<std::string> &negative_feedback, std::vector<std::string> &report, std::vector<int> &student_id, int k)
    {
        std::vector<std::string>::iterator it;
        std::vector<std::pair<int, int>> p;
        int n = report.size();
        for (int i = 0; i < n; i++)
        {
            int positive = 0, negative = 0;
            for (int j = 0; j < positive_feedback.size(); j++)
            {
               if(report[i].find(positive_feedback[j])!=report[i].npos)
                   positive++;
            }
            for (int q = 0; q < negative_feedback.size(); q++)
            {
                if(report[i].find(negative_feedback[q])!=report[i].npos)
                    negative++;
            }
            int grade = positive * 3 - negative;
            p.push_back({grade, student_id[i]});
        }
        sort(p.begin(), p.end(), [&](auto a, auto b)
             { return a.first == b.first ? a.second < b.second : a.first > b.first; });
        std::vector<int> ans(k);
        for (int i = 0; i < k; i++)
        {
            ans[i] = p[i].second;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    std::vector<std::string> good = {"smart", "brilliant", "studious"}, bad{"not"}, re{"this student is not studious", "the student is smart"};
    std::vector<int> id = {1,2};
    int k = 2;
    s.topStudents(good, bad, re, id, k);

    return 0;
}