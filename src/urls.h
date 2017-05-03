#ifndef URLS
#define URLS

#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

enum REQUEST_TYPE {
    GET, POST, PUT, DELETE, HEAD
};

void handle_connection(int, struct sockaddr_in *);
#endif
