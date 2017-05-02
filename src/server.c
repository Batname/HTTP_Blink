#include <stdio.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "utils.h"

#define PORT        8080
#define WEBROOT     "./web"

int main(int argc, const char *argv[])
{
    int sockfd, new_sockfd, yes = 1;

    // Address information
    struct sockaddr_in host_addr, client_addr;

    socklen_t sin_size;

    printf("Accepting web requests on port %d\n", PORT);

    sockfd = socket(PF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) fatal("in socket");

    return 0;
}
