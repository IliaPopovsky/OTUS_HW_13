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
    char buf[SIZE_BUF] = {0};
    char query[SIZE_BUF] = {0};
    int length = 0;
    int number_read = 0;
    int sockfd = 0;;
    struct addrinfo *result = NULL;
    struct addrinfo *temp = NULL;
    struct addrinfo hints;
    memset(&hints, 0, sizeof(struct addrinfo));
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

    //snprintf(query, sizeof(query), "figlet /%s %s\r\n", argv[1], argv[2]);
    snprintf(query, sizeof(query), "figlet /%s %s\r\n", "cosmic", "ilia");
    while( (number_read = read(sockfd, &buf[length], SIZE_BUF - length)) > 0){
	    length = length + number_read;
	    if (buf[length - 1] == '.' && buf[length - 2] == '\n')
		   break;
    }

    if(write(sockfd, query, strlen(query)) < 0){
	close (sockfd);
	printf("write error.\n");
	exit(1);
    }
    length = 0;
    number_read = 0;
    memset(buf, 0, SIZE_BUF);
    while( (number_read = read(sockfd, &buf[length], SIZE_BUF - length)) > 0){
	    length = length + number_read;
	    if (buf[length - 1] == '.' && buf[length - 2] == '\n')
		   break;
    }
    puts(buf);
    shutdown(sockfd, SHUT_RDWR);
    close (sockfd);
    return 0;
}
