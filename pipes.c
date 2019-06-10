// #include<unistd.h>
// #include <stdio.h>
// int main(){
// 	int pid;
// 	int pfd[2];
// 	char astring[5];
// 	pipe(pfd);
// 	pid = fork();
// 	if(pid == 0){
// 		write(pfd[1],"Hello" , 5);
// 		close(pfd[0]);
// 	}
// 	else{
// 		read(pfd[0] , astring , 5);
// 		printf(astring);
// 		close(pfd[1]);
// 	}
// }

#include<unistd.h>
#include <stdio.h>
#include<string.h>

int main(){
	int pfd[2];
	pipe(pfd);
	if(fork() == 0){
		close(pfd[1]);
		dup2(pfd[0],0);
		close(pfd[0]);
		execlp("wc","wc",(char *)0);
	}
	else{
		close(pfd[0]);
		dup2(pfd[1],1);
		close(pfd[1]);
		execlp("ls","ls",(char *)0);
	}
}