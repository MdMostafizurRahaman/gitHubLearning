#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int socket_desc;
    struct sockaddr_in server;

    //Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
        return 1;
    }

    //Prepare the sockaddr_in structure
    memset(&server, 0, sizeof(server));
    server.sin_addr.s_addr = inet_addr("74.125.235.20");
    server.sin_family = AF_INET;
    server.sin_port = htons(80);

    //Connect to remote server
    if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        puts("connect error");
        return 1;
    }

    puts("Connected");

    //Send some data
    char message[] = "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n";
    if (send(socket_desc, message, strlen(message), 0) < 0) {
        puts("Send failed");
        return 1;
    }

    //Receive a reply from the server
    char server_reply[2000];
    if (recv(socket_desc, server_reply, 2000, 0) < 0) {
        puts("recv failed");
    }
    puts("Server reply:");
    puts(server_reply);

    return 0;
}
