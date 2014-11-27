# ifndef _ROLIY_SOCKET
# define _ROLIY_SOCKET

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

typedef struct sockaddr sockaddr;
typedef struct sockaddr_in sockaddr_in;

void DieWithUserMessage(const char *msg, const char *detail);
void DieWithSystemMessage(const char *msg);

int Socket(int domain, int type, int protocol);
int SocketTCP4(void);
int SocketUDP4(void);
int Connect(int socket, const sockaddr *foreignAddress, socklen_t addressLength);
int Close(int socket);
int Bind(int socket, sockaddr *localAddress, socklen_t addressSize);



# endif