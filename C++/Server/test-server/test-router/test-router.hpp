/*

User defined router class

*/

#ifndef test_router_hpp
#define test_router_hpp

#include "../../networking/router/router.hpp"

namespace network {
    class TestRouter : public Router {
        private:


        public:

        TestRouter();

        void routeRequests(int sockeid);
    };
}


#endif