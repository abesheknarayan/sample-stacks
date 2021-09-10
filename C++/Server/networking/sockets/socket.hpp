
#ifndef socket_hpp
#define socket_hpp

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>

namespace network
{
    class SimpleSocket
    {
    private:
        struct sockaddr_in address;
        int sock;
        int connection;

    public:
        /*
        Creates a socket object

        * @param Domain: adress family (IP/IPv6) etc, AF_INET for IP, AF_INET for IPv6
        * @param Service: SOCK_STREAM (TCP) / SOCK_DGRAM (UDP)
        * @param Protocol: for TCP, nothing else is required so put 0
        * @param Port: port number 
        */
        SimpleSocket(int domain, int service, int protocol, int port, u_long interface);

        /*
        virtual function to connect to a network
        */
        virtual int connect_to_network(int sock, struct sockaddr_in address) = 0;


        /*
        testing if connection is properly established
        */
        void test_connection(int);


        // getters

        int get_sock();
        int get_connection();
        struct sockaddr_in get_address();

        // setters

        void set_connection(int con);
    };
}

#endif /* socket_hpp */