#include "logger.hpp"


network::Logger::Logger()
{
    set_filename("logs.txt");
}


network::Logger::Logger(std::string filename)
{
    set_filename(filename);
}

void network::Logger::set_filename(std::string fname)
{
    filename = fname;
}

std::string network::Logger::get_filename()
{
    return filename;
}

void network::Logger::Write(std::string data)
{
    // write data to file
    
    // convert filename to char *
    const char *filepath = filename.c_str();

    // open file
    std::ofstream write_obj;
    write_obj.open(filepath,std::fstream::out | std::fstream::app);

    if(!write_obj)
    {
        perror("Error in logging data onto file");
    }

    write_obj << data << "\n";
}
