#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *printHello(void *id) {
	int *myid = (int *)id;

	printf("Hello from thread\n");
}

int main() {
	pthread_t tids[3];
	int rc;
	for(int i = 0; i < 3; i++) {
		rc = pthread_create(&tids[i], NULL, printHello, (void *)&tids[i]);
	if(rc){
		printf("ERROR; return code from pthread_create() is %d\n", rc); 
        	exit(-1);
		}
	}

	pthread_exit(NULL);
}


// command: gcc threads.c -o thread -lpthread
