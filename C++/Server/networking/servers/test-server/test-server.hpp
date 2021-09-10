#ifndef testserver_hpp
#define testserver_hpp

#include "../server.hpp"
#include <unistd.h>
#include <string.h>

namespace network {
    class TestServer: public SimpleServer {
        private:
        char buffer[30000] = {0};
        int new_socket;
        void accepter();
        void handler();
        void responder();
        public:
        TestServer();
        void launch();
    };
}

#endif