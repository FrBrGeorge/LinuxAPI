#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <unistd.h>

#define NAME "the-socket"

int main()
{
    int sock, msgsock, rval;
    struct sockaddr_un server;
    char buf[1024];

    sock = socket(AF_UNIX, SOCK_STREAM, 0);
    server.sun_family = AF_UNIX;
    strcpy(server.sun_path, NAME);
    unlink(NAME);
    bind(sock, (struct sockaddr *) &server, sizeof(struct sockaddr_un));
    listen(sock, 5);
    for (;;) {
        msgsock = accept(sock, 0, 0);
        do {
            bzero(buf, sizeof(buf));
            rval = read(msgsock, buf, 1024);
            printf("-->%s\n", buf);
        } while (rval > 0);
	printf("Ending connection\n");
        close(msgsock);
    }
    close(sock);
    unlink(NAME);
}
