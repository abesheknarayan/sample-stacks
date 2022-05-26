#include "server.hpp"


network::SimpleServer::SimpleServer(int domain, int service, int protocol,int port,u_long interface, int backlog)
{
    socket = new ListeningSocket(domain,service,protocol,port,interface,backlog);
}

network::ListeningSocket* network::SimpleServer::get_socket()
{
    return socket;
}