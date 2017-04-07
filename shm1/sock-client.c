#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <unistd.h>

#define DATA "This program connects to the socket and sends a one line message"

int main(argc, argv)
    int argc;
    char *argv[];
{
    int sock;
    struct sockaddr_un server;
    char buf[1024];

    sock = socket(AF_UNIX, SOCK_STREAM, 0);
    server.sun_family = AF_UNIX;
    strcpy(server.sun_path, argv[1]);

    connect(sock, (struct sockaddr *) &server, sizeof(struct sockaddr_un));
    send(sock, DATA, sizeof(DATA), 0);
    close(sock);
}

