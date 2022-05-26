#include "./request.hpp"
#include "../../../strings/string.hpp"


// empty constructor
network::HTTPRequest::HTTPRequest(){}

void network::HTTPRequest::HTTPRequestParser(std::string _request)
{
    // get the first line
    // split by "\n" and take the first argument
    network::String requestObj(_request);
    std::string first_line = requestObj.split('\n')[0];


    network::String first_line_obj(first_line);
    std::vector<std::string> first_line_args = first_line_obj.split(' ');

    request = _request;
    request_type = first_line_args[0];
    request_route = first_line_args[1];
    protocol = first_line_args[2];

}


std::string network::HTTPRequest::get_request()
{
    return request;
}

std::string network::HTTPRequest::get_request_type()
{
    return request_type;
}


std::string network::HTTPRequest::get_request_route()
{
    return request_route;
}

std::string network::HTTPRequest::get_protocol()
{
    return protocol;
}

