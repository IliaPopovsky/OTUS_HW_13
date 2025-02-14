#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>

#define NUMBER_PORT 96
#define SIZE_BUF 1024
#define NAME_HOST "telehack.com"
#define NAME_SERVICE "telnet"

int main(int argc, char **argv)
{

    char buf[SIZE_BUF] = { 0 };
    int fd = 0;;
    struct addrinfo *result;
    struct addrinfo hints = {0};
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;
    hints.ai_protocol = IPPROTO_TCP;


    int info = getaddrinfo(NAME_HOST, NAME_SERVICE, &hints, &result);
    if (info != 0) {
	printf("getaddinfo error\n");
       exit(0);
    }

    printf("Hello world!\n");
    return 0;
}
