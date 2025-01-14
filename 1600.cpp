#include <iostream>
#include <vector>
#include <functional>
#include <unordered_map>
#include <unordered_set>

class ThroneInheritance
{
public:
    std::unordered_map<std::string, std::vector<std::string>> m;
    std::unordered_set<std::string> st;
    std::string root;
    ThroneInheritance(std::string kingName)
    {
        root = kingName;
        std::vector<std::string> v;
        m[kingName] = v;
    }

    void birth(std::string parentName, std::string childName)
    {
        m[parentName].push_back(childName);
        std::vector<std::string> v;
        m[childName] = v;
    }

    void death(std::string name)
    {
        st.emplace(name);
    }

    std::vector<std::string> getInheritanceOrder()
    {
        std::vector<std::string> ans;
        std::function<void(std::string, std::vector<std::string> &)> dfs = [&](std::string node, std::vector<std::string> &res)
        {
            if (st.find(node) == st.end())
                res.emplace_back(node);
            for (auto &child : m[node])
            {
                dfs(child, res);
            }
        };
        dfs(root, ans);
        return ans;
    }
};