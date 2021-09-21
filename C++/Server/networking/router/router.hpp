/*

Class for a generic router which acts a base class for user defined routers

*/

#ifndef router_hpp
#define router_hpp

namespace network
{
    class Router
    {
    private:
    public:
        Router();
        virtual void routeRequests(int socketid) = 0;
    };
}

#endif