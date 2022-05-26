/*

Class for a generic router which acts a base class for user defined routers

*/

#ifndef router_hpp
#define router_hpp

#include "../http/request/request.hpp"
#include "../http/response/response.hpp"

namespace network
{
    class Router
    {
    private:
    public:
        Router();
        virtual std::string routeRequests(network::HTTPRequest *request,network::HTTPResponse *response) = 0;
    };
}

#endif