#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
void error_handling(char *message);


int main(int argc, char *argv[]){
	
	int server_sfd, client_sfd;		
	struct sockaddr_in server_addr, client_addr; 
	socklen_t client_addr_size;
	char message[BUF_SIZE];
	int str_len, i;


	if(argc != 2){
		printf("Usage : %s <port> \n", argv[0]);
		exit(1);
	}

	server_sfd=socket(AF_INET, SOCK_STREAM, 0);
	if( server_sfd == -1 ) 
		error_handling("socket() error");

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family=AF_INET;
	server_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	server_addr.sin_port=htons(atoi(argv[1]));

	if( bind( server_sfd, (struct sockaddr*)&server_addr, sizeof(server_addr) ) == -1 )
		error_handling("bind() error");
	
	if( listen( server_sfd, 5 ) == -1 )
		error_handling("listen() error");
	
	client_addr_size = sizeof(server_addr);

	for( i = 0 ; i < 5 ; i++ ){
		
		client_sfd = accept( server_sfd, (struct sockaddr*)&client_addr, &client_addr_size);
		if( client_sfd == -1 ) 
			error_handling("accept() error");
		else
			printf("Connected client %d", i+1);

		while( (str_len = read(client_sfd, message, BUF_SIZE)) != 0 ){
			write(client_sfd, message, str_len);
		} 

		close(client_sfd);
					
	}
	close(server_sfd);
	return 0;	
}

void error_handling(char *message){
	fputs(message, stderr);
	fputc('\n',stderr);
	exit(1);
}





























