#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <algorithm>

class Solution
{
public:
    std::vector<int> maximumSumQueries(std::vector<int> &nums1, std::vector<int> &nums2, std::vector<std::vector<int>> &queries)
    {
        int n = nums1.size();
        std::vector<int> ans(queries.size());
        std::vector<std::pair<int, int>> pa(n);
        std::vector<std::pair<int, int>> st;
        std::vector<int> v(queries.size());

        std::iota(v.begin(),v.end(),0);
        sort(v.begin(), v.end(), [&](int a, int b){ 
            return queries[a][0] > queries[b][0];
        });

        for (int i = 0; i < n; i++)
            pa[i] = {nums1[i], nums2[i]};
        sort(pa.begin(), pa.end(), [](auto &a, auto &b){ 
                return a.first > b.first;
        });

        int i = 0;
        for(int a:v){
            int x = queries[a][0], y = queries[a][1];
            for (; i < pa.size() && pa[i].first >= x; i++){
                while(!st.empty() && st.back().second <= pa[i].first + pa[i].second){
                    st.pop_back();
                }
                if(st.empty() || st.back().first < pa[i].second){
                    st.emplace_back(pa[i].second, pa[i].first + pa[i].second);
                }
            }
            auto it = std::lower_bound(st.begin(), st.end(), y, [](const auto &t, int value)
            {
                   return t.first < value; 
            });
            ans[a] = it != st.end() ? it->second : -1;
        }
        return ans;
    }
};


int main(){
    std::vector<std::vector<int>> quer = {{4,1},{1,3},{2,5}};
    std::vector<int> v1 = {4, 3, 1, 2};
    std::vector<int> v2 = {2, 4, 9, 5};
    Solution s;
    s.maximumSumQueries(v1, v2, quer);

    return 0;
}