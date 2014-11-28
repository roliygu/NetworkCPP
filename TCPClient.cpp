#include <iostream>
#include "socket.h"
using namespace std;

extern const int SERV_PORT;
extern const int MAXLINE;

void str_cli(FILE *fp, int sock){
	char sendline[MAXLINE], recvline[MAXLINE];
	while(fgets(sendline, MAXLINE, fp) != NULL){
		Writen(sock, sendline, strlen(sendline));
		if(Readline(sock, recvline, MAXLINE) == 0)
			DieWithSystemMessage("str_cli: server terminated prematurely");
		fputs(recvline, stdout);
	}
}


int main(int argc, char *argv[]){
	if(argc != 2)
		DieWithUserMessage("Parameters", "<IPaddress>");
	int sock = SocketTCP4();
	sockaddr_in servaddr;
	SetCliServAddr(&servaddr, argv[1]);
	Connect(sock, (sockaddr *) &servaddr, sizeof(servaddr));
	str_cli(stdin, sock);
	exit(0);
}