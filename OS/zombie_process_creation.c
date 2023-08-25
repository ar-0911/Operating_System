#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
	
	int a,b,c;
	int pid = fork();
	
	//parent process
	if(pid>0){
		printf("Parent process if going to sleep\n");
		sleep(10);
		printf("The parent process is resumed\n");
	}
	
	//child process
	else{
		printf("\nChild process executing");
		printf("\nChild terminates");
		exit(0);
	}
	
	return 0;	
}