#include<iostream>
#include<stack>
using namespace std;

/*暴力模拟*/
class Solution {
public:
  stack<char>st;
  bool cheak(char l,char r){
   if(r == ')'&& l == '(')return true;
   else if(r == ']'&& l == '[')return true;
   else if(r == '}'&& l == '{')return true;
   else return false;
  }

  bool isValid(string s) {
    int n = s.length();
    if(n == 0)return true;
    for(int i = 0 ;i < n ; i++){
        if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
        if(st.empty() || !cheak(st.top(),s[i])){
          return false;
        }
        else st.pop();
        }
        else st.push(s[i]);
    }
    return st.empty();
  }
};