#ifndef VIEWS
#define VIEWS

void views_index(int sockfd, int length, char *ptr);
void views_turnon(int sockfd);
void views_turnof(int sockfd);
void views_not_found(int sockfd);

#endif
