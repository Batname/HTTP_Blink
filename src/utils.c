#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

void fatal(char *message)
{
    char error_message[100];
    strcpy(error_message, "[!!] Fatal Error ");
    strncat(error_message, message, 83);
    perror(error_message);
    exit(-1);
}

int send_string(int sockfd, unsigned char *buffer)
{
    return 1;
}

int recive_line(int sockfd, unsigned char *dest_buffer)
{
    return 1;
}
