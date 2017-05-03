#include <stdlib.h>

#include "urls.h"
#include "utils.h"
#include "views.h"

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
            if (ptr[strlen(ptr) - 2] == '/' && strlen(ptr) == 2 && request_type == GET) 
            {
                views_index(sockfd);
            }
            else if (strncmp(ptr, "/turn-on ", 9) == 0 && request_type == POST)
            {
                views_turnon(sockfd);
            }        
            else if (strncmp(ptr, "/turn-off ", 10) == 0 && request_type == POST)
            {
                views_turnof(sockfd);
            }
            else {
                views_not_found(sockfd);
            }
        }
    }

    shutdown(sockfd, SHUT_RDWR);
}
