#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int getpid();
int getppid();
int fork();
int wait(int*);
int main() 
{ 
	pid_t pid;
	pid = fork();
	if(pid == 0){
		printf("Child process created with childID: %d\n", getpid());
		printf("Parent process ID: %d\n", getppid());
		exit(0);
	}else{
		pid = wait(23);
		printf("Child process terminated, process returned to parent with ID: %d\n", getppid());
	}
} 



