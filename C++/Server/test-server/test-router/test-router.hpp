/*

User defined router class

*/

#ifndef test_router_hpp
#define test_router_hpp


#include "../../networking/router/router.hpp"
#include "../../networking/http/request/request.hpp"
#include "../../networking/http/response/response.hpp"

namespace network {
    class TestRouter : public Router {
        private:


        public:

        TestRouter();

        std::string routeRequests(network::HTTPRequest *request,network::HTTPResponse *response);
    };
}


#endif