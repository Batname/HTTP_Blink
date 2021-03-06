#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

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
    int sent_bytes, bytes_to_send;
    bytes_to_send = strlen(buffer);
    
    while(bytes_to_send > 0)
    {
        sent_bytes = send(sockfd, buffer, bytes_to_send, 0);
        if (sent_bytes == -1)
            return 0; // sent error

        bytes_to_send -= sent_bytes;
        buffer += sent_bytes;
    }

    return 1; // return 1 on success
}

int recv_line(int sockfd, unsigned char *dest_buffer)
{
#define EOL "\r\n" // End-Of-Line byte sequence
#define EOL_SIZE 2
   unsigned char *ptr;
   int eol_matched = 0;

   ptr = dest_buffer;
   while(recv(sockfd, ptr, 1, 0) == 1) { // read a single byte
      if(*ptr == EOL[eol_matched]) { // does this byte match terminator
         eol_matched++;
         if(eol_matched == EOL_SIZE) { // if all bytes match terminator,
            *(ptr+1-EOL_SIZE) = '\0'; // terminate the string
            return strlen(dest_buffer); // return bytes recevied
         }
      } else {
         eol_matched = 0;
      }   
      ptr++; // increment the pointer to the next byter;
   }
   return 0; // didn't find the end of line characters
}

int get_file_size(int fd) {
    struct stat stat_struct;
    if(fstat(fd, &stat_struct) == -1)
        return -1;
    return (int) stat_struct.st_size;
}

