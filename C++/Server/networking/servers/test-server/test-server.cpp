#include "test-server.hpp"


network::TestServer::TestServer(): SimpleServer(AF_INET,SOCK_STREAM,0,80,INADDR_ANY,10)
{
    launch();
}

void network::TestServer::accepter()
{
    struct sockaddr_in address = get_socket()->get_address();
    int address_len = sizeof(address);

    new_socket = accept(get_socket()->get_sock(),(struct sockaddr*)&address,(socklen_t*)&address_len);    

    read(new_socket,buffer,30000);  
}

void network::TestServer::handler()
{
    std::cout<<buffer<<"\n";
}

void network::TestServer::responder()
{
    char *response = "Hello from Abeshek server";

    write(new_socket,response,strlen(response));
}

void network::TestServer::launch()
{
    while(true)
    {
        std::cout<<" Server listening...\n";
        accepter();
        handler();
        responder();
        std::cout<<" Response sent back to client\n";
    }
}