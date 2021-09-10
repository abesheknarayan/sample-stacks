#ifndef server_hpp
#define server_hpp

#include "../networking.hpp"

namespace network {
    class SimpleServer
    {
        private:
        ListeningSocket* socket;

        virtual void accepter() = 0;
        virtual void handler() = 0;
        virtual void responder() = 0;
        public:
        SimpleServer(int domain, int service, int protocol,int port,u_long interface, int backlog);
        virtual void launch() = 0;

        ListeningSocket* get_socket();

    };
}

#endif