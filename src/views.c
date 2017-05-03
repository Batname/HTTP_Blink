#include <fcntl.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <string.h>

#include "views.h"
#include "utils.h"

#define WEBROOT     "./web"

void views_index(int sockfd, int length, char *ptr)
{
    int fd;
    unsigned char resource[500];

    strcat(ptr, "index.html");
    strcpy(resource, WEBROOT);
    
    // Begin resource with web root path
    strcat(resource, ptr);
    // and join it with resource path.
    fd = open(resource, O_RDONLY, 0); // Try to open the file.
    
    printf("\tOpening \'%s\'\t", resource);

    if(fd == -1) { // If file is not found
        printf(" 404 Not Found\n");
        send_string(sockfd, "HTTP/1.0 404 NOT FOUND\r\n");
        send_string(sockfd, "Server: Tiny webserver\r\n\r\n");
        send_string(sockfd, "<html><head><title>404 Not Found</title></head>");
        send_string(sockfd, "<body><h1>FILE not found</h1></body></html>\r\n");
    } else {
        send_string(sockfd, "HTTP/1.0 200 OK\r\n");
        send_string(sockfd, "Server: Tiny webserver\r\n\r\n");
    
        if( (length = get_file_size(fd)) == -1)
            fatal("getting resource file size");
        if( (ptr = (unsigned char *) malloc(length)) == NULL)
            fatal("allocating memory for reading resource");
    
        read(fd, ptr, length); // Read the file into memory.
        send(sockfd, ptr, length, 0); // Send it to socket.
        free(ptr); // Free file memory.
        close(fd);
    }
}

void views_turnon(int sockfd)
{
    send_string(sockfd, "HTTP/1.0 200 OK\r\n");
    send_string(sockfd, "Content-Type: application/json\r\n");
    send_string(sockfd, "Server: Tiny webserver\r\n\r\n");
    send_string(sockfd, "{\"status\": \"ok\"}\r\n");
}

void views_turnof(int sockfd)
{
    send_string(sockfd, "HTTP/1.0 200 OK\r\n");
    send_string(sockfd, "Content-Type: application/json\r\n");
    send_string(sockfd, "Server: Tiny webserver\r\n\r\n");
    send_string(sockfd, "{\"status\": \"ok\"}\r\n");
}

void views_not_found(int sockfd)
{
    send_string(sockfd, "HTTP/1.0 200 OK\r\n");
    send_string(sockfd, "Server: Tiny webserver\r\n\r\n");
    send_string(sockfd, "<html><head><title>200 OK</title></head>");
    send_string(sockfd, "<body><h1>OK</h1></body></html>\r\n");
}
