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
    printf("Hello world!\n");
    return 0;
}
