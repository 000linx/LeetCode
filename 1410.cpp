#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::string entityParser(std::string text)
    {
        std::unordered_map<std::string, std::string> M;
        M["&quot;"] = '\"';
        M["&apos;"] = "'";
        M["&amp;"] = '&';
        M["&gt;"] = '>';
        M["&lt;"] = '<';
        M["&frasl;"] = '/';
        for (int i = 0; i < text.length(); i++){
            if(text[i] == '&'){
                std::string str = "";
                bool ok = true;
                str += text[i];
                for (int j = i + 1; j < text.length();j++){
                    if(!ok){
                        break;
                    }
                    str += text[j];
                    for(const auto &pair :M){
                        if(str == pair.first){
                            text.replace(i, str.length(), pair.second);
                            ok = false;
                            str = "";
                            break;
                        }
                    }
                }   
            }
            
            
        }
        return text;
    }
};


int main(){
    Solution s;
    std::string s1 = "&&gt;";
    s.entityParser(s1);
}