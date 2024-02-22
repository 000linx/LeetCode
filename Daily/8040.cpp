#include<bits/stdc++.h>
using namespace std;


int main(){
    string num;
    cin >> num;
    int n =num.length();
    int ans = 0;
    for(int i = 0 ;i < n ;i++){
        if((num[n-1]*10 -'0' + num[n - 2] - '0') % 25 == 0)break;
         
    }


}