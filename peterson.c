#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool flag[2]={false,false};
double balance = 0;
double temp1 = 0;
doubletemp2 = 0;
int turn; 
void *credit(void * arg){
	int a = *(int *) arg;
	 flag[0] =true;
	  turn = 1;
	   while(flag[1] && turn == 1) ;
	    balance = balance + a;
	    flag[0]=false;
	}
	void *debit(void * arg)
	{ 
		int a = *(int *) arg;
		flag[1] = true;
		 turn = 0;
		  while(flag[0] && turn == 0) ;
		   balance = balance-a;
		   flag[1] = false;
	 }

	 int main(){ 
	 	int choice;
	 	pthread_t credit_thread, debit_thread; 
	 	while(1){system("clear");
	 	printf("Name: Student \nAcc No.: 420\n");
	 	printf("Available Balance: Rs. %f/-\n", balance);
	 	 printf("Enter amount to credit\n"); scanf("%d", &temp1);
	 	  printf("Enter amount to Debit\n"); scanf("%d", &temp2);
	 	   pthread_create(&credit_thread, NULL,credit, &temp1);
	 	   pthread_create(&debit_thread, NULL, debit, &temp2);
	 	}
	 	pthread_join(credit_thread, NULL);
	 	 pthread_join(debit_thread, NULL);
	 	  printf("Account Summary:\n----------------\n");
	 	   printf("Available Balance: Rs. %f/-\n", balance);
	 	    exit(0);
	 	}