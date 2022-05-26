/*
 
Contains some helper functions for strings

*/

#ifndef string_hpp
#define string_hpp

#include <string>
#include <vector>

namespace network
{
    class String
    {
    private:
        std::string value;

    public:
        // constructor
        String(std::string _value);

        // splits the string with given character 
        std::vector<std::string> split(char c);
    };
}

#endif