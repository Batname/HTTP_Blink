#ifndef UTILS
#define UTILS
void fatal(char *message);
int send_string(int sockfd, unsigned char *buffer);
int recive_line(int sockfd, unsigned char *dest_buffer);

#endif
