#include <iostream>
#include "socket.h"
using namespace std;

extern const int SERV_PORT;
extern const int MAXLINE;

void str_echo(int sockfd){
	ssize_t n;
	char buffer[MAXLINE];
again:
	while( (n = read(sockfd, buffer, MAXLINE)) > 0)
		Writen(sockfd, buffer, n);
	if(n < 0 && errno == EINTR)
		goto again;
	else if (n < 0)
		DieWithSystemMessage("str_echo: read error");
}


int main(int argc, char *argv[]){
	sockaddr_in cliaddr, servaddr;
	int listensock = SocketTCP4();
	SetServServAddr(&servaddr);
	Bind(listensock, (sockaddr *) &servaddr, sizeof(servaddr));
	Listen(listensock, 1);
	pid_t childpid;
	for(;;){
		socklen_t clilen;
		int connsock = Accept(listensock, (sockaddr *) &cliaddr, &clilen);
		if( (childpid = fork()) == 0){
			Close(listensock);
			str_echo(connsock);
			exit(0);
		}
		Close(connsock);
	}
}