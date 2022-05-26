#ifndef logger_hpp
#define logger_hpp

#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>


namespace network
{
    class Logger
    {
    private:
        std::string filename;

    public:
        // constructor
        Logger();
        Logger(std::string filename);
        // writes the data onto file
        void Write(std::string data);

        // getters
        std::string get_filename();

        // setters
        void set_filename(std::string filename);
    };
}

#endif