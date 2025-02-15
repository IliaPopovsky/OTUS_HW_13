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
    #if 0
    if (argc < 3) {
		printf("you must enter the font name as the first argument and the text to convert as the second argument");
		exit(1);
	}
    #endif
    char *font = argv[1];
	char *text = argv[2];
    char buf[SIZE_BUF] = { 0 };
    int sockfd = 0;;
    struct addrinfo *result = NULL;
    struct addrinfo *temp = NULL;
    struct addrinfo hints = {0};
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;
    hints.ai_protocol = IPPROTO_TCP;


    int info = getaddrinfo(NAME_HOST, NAME_SERVICE, &hints, &result);
    if (info != 0) {
	    printf("getaddinfo error\n");
        exit(1);
    }

    for(temp = result; temp != NULL; temp = temp->ai_next) {
		sockfd = socket(temp->ai_family, temp->ai_socktype, temp->ai_protocol);
		if (sockfd == -1)
			continue;
		if (connect(sockfd, temp->ai_addr, temp->ai_addrlen) == 0) {
			break;
		}
		close(sockfd);
    }

    if(temp == NULL){
       printf("connect error\n");
       exit(1);
    }
    freeaddrinfo(result);


    printf("Hello world!\n");
    return 0;
}
