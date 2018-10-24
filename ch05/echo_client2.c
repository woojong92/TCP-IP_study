#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
void error_handling(char *message);

int main(int argc, char *argv[]){

	int sockfd;
	struct sockaddr_in server_addr;	
	char message[BUF_SIZE];
	int str_len, recv_len, recv_cnt;

	if(argc != 3){
		printf("Usage : %s <IP> <port> \n", argv[0]);
		exit(1);
	}

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if( sockfd == -1 )	
		error_handling("socket() error");

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family=AF_INET;
	server_addr.sin_addr.s_addr=inet_addr(argv[1]);
	server_addr.sin_port=htons(atoi(argv[2]));

	if( connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1 )
		error_handling("connect() error");
	else 
		puts("Connected............");

	while(1){

		fputs("Input message(Q to quit): ", stdout);
		fgets(message, BUF_SIZE, stdin);

		if( !strcmp(message, "q\n") || !strcmp(message, "Q\n") )
			break;

		str_len = write(sockfd, message, strlen(message));

		recv_len = 0;
		while( recv_len < str_len ){
			recv_cnt = read(sockfd, &message[recv_len], BUF_SIZE-1);
			if(recv_cnt == -1)
				error_handling("read() error");
			
			recv_len += recv_cnt;
		}
	
		message[recv_len]=0;
		printf("Message from server: %s", message);
	}
	close(sockfd);

	return 0;
}

void error_handling(char *message){
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}






















