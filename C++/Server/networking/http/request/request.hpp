/*

Class for handling requests

*/

#ifndef request_hpp
#define request_hpp

#include <string>
#include <vector>
#include <iostream>

namespace network
{
    class HTTPRequest
    {
    private:
        std::string request;       // the reqest itself unparsed
        std::string request_type;  // GET / POST / PUT
        std::string request_route; // route such as /index.html
        std::string protocol;      // as of now only HTTP/1.1

    public:

        // empty constructor is enough as only after parsing we will get variables
        HTTPRequest();

        // parses the HTTP request onto different fields and stores it in private variables
        void HTTPRequestParser(std::string _request);

        // getters
        std::string get_request();
        std::string get_request_type();
        std::string get_request_route();
        std::string get_protocol();
    };
}

#endif