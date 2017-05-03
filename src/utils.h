#ifndef UTILS
#define UTILS

void fatal(char *message);
int send_string(int sockfd, unsigned char *buffer);
int recv_line(int sockfd, unsigned char *dest_buffer);
int get_file_size(int fd);

#endif
