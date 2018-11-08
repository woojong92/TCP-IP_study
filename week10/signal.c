#include <stdio.h>
#include <unistd.h>
#include <signal.h>

/**
* 1. USER DEFINE
* 2. SIG_DFL: default.
* 3. SIG_IGN: IGNORE.
*/


void timeout(int sig){
	if(sig == SIGALRM)
		puts("time out!");
	alarm(2);
}

void keycontrol(int sig){
	if(sig == SIGINT)
		puts("CTRL+C pressed");

	signal(SIGINT, SIG_DFL); // SIG_DFL: default.
}

int main(int argc, char* argv[]){

	int i;
	signal(SIGALRM, timeout);
	//signal(SIGINT, keycontrol);
	signal(SIGINT, SIG_IGN); // SIG_IGN: IGNORE.
	alarm(2);
		
	for( i =0; i< 3; i++){
		puts("wait...");
		sleep(100);
	}


	return 0;
}
