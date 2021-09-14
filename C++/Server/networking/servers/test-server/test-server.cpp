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
    // have a HTTPResponse object
    network::HTTPResponse new_response(
        int(200),
        std::string("OK"),
        std::string("HTTP/1.1"),
        std::string("text/html"),
        std::string("Abeshek's C++ server"),
        std::string("Wed, 18 Jun 2009 16:05:58 GMT"),
        std::string("Wed, 18 Jun 2003 16:05:58 GMT"),
        std::string("bytes"),
        std::string("SAMEORIGIN"),
        std::string("gzip"),
        std::string("close")
    );

    // getting a string rather than const char * because returning a pointer from a function leads to null pointer as pointer will be erased after function is executed
    // std::string response = new_response.SentTextResponse(std::string("Hello from Abeshek custom built c++ server"));

    std::string response = new_response.SendHTMLFileAsResponse("../../Frontend/html/index.html"); 


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