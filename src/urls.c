#include <stdlib.h>

#include "urls.h"
#include "utils.h"

void handle_connection(int sockfd, struct sockaddr_in *client_addr)
{
    unsigned char *ptr, request[500], responce[500];
    int fd, length;
    enum REQUEST_TYPE request_type;

    length = recv_line(sockfd, request);

    printf("Got request from %s:%d \"%s\"\n", inet_ntoa(client_addr->sin_addr),
ntohs(client_addr->sin_port), request);

    ptr = strstr(request, "HTTP/"); // search for valid request
    if (ptr == NULL)
        printf(" NOT HTTP!\n");
    else
    {
        *ptr = 0; // terminate the buffer at the and of URL
        ptr = NULL;

        if (strncmp(request, "GET ", 4) == 0) // GET request
        {
            request_type = GET;
            ptr = request + 4; // ptr is the URL.
        }
        if (strncmp(request, "HEAD ", 5) == 0) // HEAD request
        {
            request_type = HEAD;
            ptr = request + 5; // ptr is the URL.
        }
        if (strncmp(request, "POST ", 5) == 0)
        {
            request_type = POST;
            ptr = request + 5;
        }
        

        if (ptr == NULL)
            printf("\tUNKNOWN REQUST!\n");
        else
        {
            if (ptr[strlen(ptr) - 2] == '/' && strlen(ptr) == 2) // TODO, why 2
            {
                printf("Home page\n");
            }
            if (strncmp(ptr, "/turn-on ", 9) == 0)
            {
                printf("turn-on\n");
            }        
            if (strncmp(ptr, "/turn-off ", 10) == 0)
            {
                printf("turn-off\n");
            } 
        }
    }


    // FOR TEST
    send_string(sockfd, "HTTP/1.0 200 OK\r\n");
    send_string(sockfd, "Server: Tiny webserver\r\n\r\n");
    send_string(sockfd, "<html><head><title>200 OK</title></head>");
    send_string(sockfd, "<body><h1>OK</h1></body></html>\r\n");

    shutdown(sockfd, SHUT_RDWR);
}
