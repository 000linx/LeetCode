#include <iostream>
#include <vector>
#include <unordered_map>


/*dp*/
class Solution
{
public:
    int getMaxRepetitions(std::string s1, int n1, std::string s2, int n2)
    {
        std::vector<int> v(s2.size());
        for (int i = 0; i < s2.size();i++){
            int j = i;
            for (int k = 0; k < s1.size();k++){
                if(s1[k] == s2[j]){
                    v[i]++;
                    j = (j + 1) % s2.size();
                }
            }
        }
        int temp = 0, ans = 0;
        for (int i = 0; i < n1; i++){
            int a = v[temp];
            temp = (temp + a) % s2.size();
            ans += a;
        }
        return ans / (n2*s2.size());
    }
};

int main()
{
    Solution s;
    std::string s1 = "baba";
    std::string s2 = "baab";

    s.getMaxRepetitions(s1, 11, s2, 1);
    return 0;
}