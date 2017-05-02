#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "utils.h"
#include "urls.h"

#define PORT        8080
#define WEBROOT     "./web"

int main(int argc, const char *argv[])
{
    int sockfd, new_sockfd, status, yes = 1;

    // Address information
    struct sockaddr_in host_addr, client_addr;

    socklen_t sin_size;

    printf("Accepting web requests on port %d\n", PORT);

    sockfd = socket(PF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) fatal("in socket");
    
    status = setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
    if (status == -1) fatal("setting socket option SO_REUSEADDR");

    host_addr.sin_family = AF_INET;                 // Host byte order
    host_addr.sin_port = htons(PORT);               // Short network byte order
    host_addr.sin_addr.s_addr = INADDR_ANY;         // Auto fill my IP
    memset(&(host_addr.sin_zero), '\0', 8);         // Zero the rest of the struct

    status = bind(sockfd, (struct sockaddr*)&host_addr, sizeof(struct sockaddr));
    if (status == -1) fatal("binding to socket");

    status = listen(sockfd, 20);
    if (status == -1) fatal("listening on socket");

    // server loop
    while(1)
    {
        sin_size = sizeof(struct sockaddr_in);
        new_sockfd = accept(sockfd, (struct sockaddr*)&client_addr, &sin_size);
        if (new_sockfd == -1) fatal("accepting connection");

        handle_connection(new_sockfd, &client_addr);
    }

    return 0;
}
