#include<stdio.h>
#include<sys/socket.h>
int main(int argc, char *argv[])
{
	int socket_desc = socket(AF_INET,SOCK_STREAM,0);
	printf("Socket_desc:%d\n",socket_desc);
}