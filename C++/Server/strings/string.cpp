#include "string.hpp"

network::String::String(std::string _value)
{
    value = _value;
}


// returns a vector of strings which is splitted according to character c
std::vector<std::string> network::String::split(char c)
{
    std::vector<std::string> ans;

    std::string temp = "";
    for (auto _c : value)
    {
        if(_c == c)
        {
            ans.push_back(temp);
            temp.clear();
        }
        else{
            temp += _c;
        }
    }
    if(temp.length())
    {
        ans.push_back(temp);
    }
    return ans;
}