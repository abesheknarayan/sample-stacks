
#ifndef listeningsocket_hpp
#define listening_socket_hpp

#include <stdio.h>

#include "bindingsocket.hpp"

namespace network {
    class ListeningSocket: public BindingSocket {
        private: 
           int backlog;
           int listening;
        public:
            ListeningSocket(int domain, int service, int protocol, int port, u_long interface, int backlog);

            void start_listening();

    };    
}

#endif