#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>

void *counter(void *arg) {
	int i;
 
	for ( i = 0; i< 10; i++ ) {
		printf("%d\n", i);
	}

	pthread_exit(0);
}

int main() {
	pthread_t th[3];
	
	for ( int i = 0; i < 3; i++ ) 
		pthread_create(&th[i], NULL, counter, NULL);

	for ( int i = 0; i < 3; i++ )
		pthread_join(th[i], NULL);

	pthread_exit(0);
}

