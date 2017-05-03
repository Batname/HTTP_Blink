#include "views.h"
#include "utils.h"


void views_index(int sockfd)
{

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
