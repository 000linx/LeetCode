#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    getline(cin,a);
    getline(cin, b);
    string str = a + b;
    unordered_map<char,int> st;
    for (int i = 0; i < str.size(); i++){
        st[str[i]]++;
    }
    for (int i = 0; i < str.size(); i++){
        if(st[str[i]] != 0){
            cout << str[i];
        }
        st[str[i]] = 0;
    }
        return 0;
}