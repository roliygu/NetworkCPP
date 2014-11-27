#include "socket.h"

void DieWithUserMessage(const char *msg, const char *detail){
	fputs(msg, stderr);
	fputs(": ", stderr);
	fputs(detail, stderr);
	fputc('\n', stderr);
	exit(1);
}
void DieWithSystemMessage(const char *msg){
	perror(msg);
	exit(1);
}
int Socket(int domain, int type, int protocol){
	int sock;
	sock = socket(domain, type, protocol);
	if(sock<0)
		DieWithSystemMessage("socket() failed");
	return sock;
}
int SocketTCP4(void){
	return Socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
}
int SocketUDP4(void){
	return Socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
}
int Close(int socket){
	int n;
	n = close(socket);
	if(n<0)
		DieWithSystemMessage("close() failed");
	return n;
}
int Connect(int socket, const sockaddr *foreignAddress, socklen_t addressLength){
	int n;
	n = connect(socket, foreignAddress, addressLength);
	if(n<0)
		DieWithSystemMessage("connect() failed");
	return n;
}
int Bind(int socket, sockaddr *localAddress, socklen_t addressSize){
	int n;
	n = bind(socket, localAddress, addressSize);
	if(n<0)
		DieWithSystemMessage("bind() failed");
	return n;
}