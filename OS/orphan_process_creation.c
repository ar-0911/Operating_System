#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
	
	int pid;
	pid = fork();
	
	if(pid==0){
		printf("I am the child my process ID is %d\n",getpid());
		printf("My parents process ID is %d\n",getppid());
		sleep(6);
		printf("\nAfter sleep\nI am the child, my process ID is %d\n",getpid());
		printf("My parents process ID is %d\n",getppid());
	}
	
	else{
		sleep(3);
		printf("I am the parent, my process ID is %d\n",getpid());
		printf("The parent's parent, process ID is %d\n",getppid());
		printf("Parent terminates\n");
	}
	
	return 0;
}