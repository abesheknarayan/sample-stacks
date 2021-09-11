#include "test-server.hpp"
#include "../../http/response.hpp"

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
}

void network::TestServer::handler()
{
    // log responses to a file using a logger class
    log.set_filename("../logs/logs.txt");
    log.Write(buffer);
}

void network::TestServer::responder()
{
    // char *response = "Hello from Abeshek server";
    // std::string resp = "HTTP/1.1 200 OK\n"
    // "Date: Thu, 19 Feb 2009 12:27:04 GMT\n"
    // "Server: Apache/2.2.3\n"
    // "Last-Modified: Wed, 18 Jun 2003 16:05:58 GMT\n"
    // "ETag: \"56d-9989200-1132c580\"\n"
    // "Content-Type: text/html\n"
    // "Content-Length: 15\n"
    // "Accept-Ranges: bytes\n"
    // "Connection: close\n"
    // "\n"
    // "Hello from Abeshek's C++ Server";
    
    // have a HTTPResponse object
    network::HTTPResponse new_response(
        int(200),
        std::string("OK"),
        std::string("HTTP/1.1"),
        std::string("text/html"),
        std::string("Abeshek's C++ server"),
        std::string("Sat Sep 11 2021 13:50:25 GMT+0530 (India Standard Time)"),
        std::string("Sat May 4 2020 13:50:25 GMT+0530 (India Standard Time)"),
        std::string("bytes"),
        std::string("SAMEORIGIN"),
        std::string("gzip")
    );

    // char *resp = new_response.SentTextResponse(std::string("Hello from Abeshek server built with c++ from scratch")); 

    // write(new_socket, response, strlen(response));
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