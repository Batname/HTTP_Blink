#include "urls.h"
#include "utils.h"

void handle_connection(int sockfd, struct sockaddr_in *client_addr)
{
    unsigned char *ptr, request[500], responce[500];
    int fd, length;

    //length = recv_line(sockfd, request);

    printf("Got request from %s:%d \"%s\"\n", inet_ntoa(client_addr->sin_addr),
ntohs(client_addr->sin_port), request);


    // FOR TEST
    //send_string(sockfd, "HTTP/1.0 200 OK\r\n");
    //send_string(sockfd, "Server: Tiny webserver\r\n\r\n");
    //send_string(sockfd, "<html><head><title>200 OK</title></head>");
    //send_string(sockfd, "<body><h1>OK</h1></body></html>\r\n");

    shutdown(sockfd, SHUT_RDWR);
}
