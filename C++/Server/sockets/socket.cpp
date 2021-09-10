#include "socket.hpp"


network::SimpleSocket::SimpleSocket(int domain, int service, int protocol, int port, u_long interface)
{

    // Define Address structure
    address.sin_family = domain;
    // convert to network endian format
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(interface);

    // create a socket
    sock = socket(domain,service,protocol);

    // establish network connection, either bind / connect
    // connection = connect_to_network(sock,address);

    test_connection(connection);
}

void network::SimpleSocket::test_connection(int test)
{
    if(test < 0)
    {
        perror("Error in creating sockets");
        exit(EXIT_FAILURE);
    }
}


int network::SimpleSocket::get_sock()
{
    return sock;
}

int network::SimpleSocket::get_connection()
{
    return connection;
}

struct sockaddr_in network::SimpleSocket::get_address()
{
    return address;
}

// setters

void network::SimpleSocket::set_connection(int con)
{
    connection = con;
}