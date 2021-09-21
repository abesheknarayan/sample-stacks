#include "test-server.hpp"
#include "../networking/http/response/response.hpp"

network::TestServer::TestServer() : SimpleServer(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY, 10)
{
    launch();
}

void network::TestServer::accepter()
{
    struct sockaddr_in address = get_socket()->get_address();
    int address_len = sizeof(address);

    new_socket = accept(get_socket()->get_sock(), (struct sockaddr *)&address, (socklen_t *)&address_len);

    read(new_socket, buffer, 30000);

    // log responses to a file using a logger class

    log.set_filename("logs/logs.txt");
    log.Write(buffer);

    // Parse the HTTP request
    /*
        1. First line seperated by spaces
        2. From that all lines are key:value pairs (not very important at the moment) --> might be needed when sessions are involved

    */
   request.HTTPRequestParser(buffer);
}

void network::TestServer::handler()
{
    // do stuff on post requests    

    if(request.get_request_type() == "GET")
    {
        return;
    }
    
    // post

    if(request.get_request_type() == "POST")
    {
    }

}

void network::TestServer::responder()
{   
    // have a HTTPResponse object
    network::HTTPResponse new_response;
    new_response.set_protocol("HTTP/1.1");
    new_response.set_content_type("text/html");
    new_response.set_server_name("Abeshek's Server");
    new_response.set_response_time("Wed, 21 Sep 2021 06:05:58 GMT");
    new_response.set_last_modified("Wed, 21 Sep 2021 06:05:58 GMT");
    new_response.set_accept_ranges("bytes");
    new_response.set_X_Frame_Options("SAMEORIGIN");
    new_response.set_content_encoding("gzip");
    new_response.set_connection("close");

    // getting a string rather than const char * because returning a pointer from a function leads to null pointer as pointer will be erased after function is executed
    std::string response = router.routeRequests(&request,&new_response);

    write(new_socket, response.c_str(), strlen(response.c_str()));
}

void network::TestServer::launch()
{
    while (true)
    {
        std::cout << " Server listening...\n";
        accepter();
        handler();
        responder();
        std::cout << " Response sent back to client\n";
    }
}