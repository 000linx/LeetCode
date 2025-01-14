#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

int main(){
    vector<int> number = {1, 2, 3, 4, 5, 6};
    int n = number.size();
    vector<int> v(n + 1);
    // partial_sum 求前缀和
    partial_sum(number.begin(),number.end(),v.begin() + 1);
    return 0;
}