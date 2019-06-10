#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

int myGlobal = 0;
pthread_mutex_t myMutex;
void *threadFunction()
	{
		int i, j;
		for (i = 0; i<10; i++){
			pthread_mutex_lock(&myMutex);
			j = myGlobal;
			j = j+1;
			myGlobal = j;
			printf("\n My Global Is: %d\n", myGlobal);
			pthread_mutex_unlock(&myMutex);
			sleep(1);
		}
	}
		int main(){
			pthread_t myThread1,myThread2;
			int i,k;
			pthread_create(&myThread1, NULL,threadFunction,NULL);
			pthread_create(&myThread2, NULL,threadFunction,NULL);
			pthread_join(myThread1, NULL);
			pthread_join(myThread2, NULL);
			printf("\nMy Global Is: %d\n", myGlobal);
			exit(0);
		}