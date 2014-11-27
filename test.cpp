#include <iostream>
#include "socket.h"
using namespace std;

int main(){
	int n = SocketUDP4();
	cout<<n<<endl;
	return 0;
}