#include<stdio.h>
#include<stdlib.h>
int getpid();
int getppid();
int fork();
void sleep();
int main(){
	int pid, pid1, pid2, pid3;


	// lets get an id using fork;
	pid = fork();
	if(pid == 0){
	sleep(4);
	printf("child[4] created with pid %d from parent[1] with pid %d\n", getpid(), getppid());	
	}
	
	else
	{
	pid1 = fork();
	if(pid1 == 0){
	sleep(3);
	printf("Child[3] created with pid %d from parent with pid %d\n", getpid(), getppid());
	}

	else
	{
	pid2 = fork();
	if(pid2 == 0){
	sleep(2);
	printf("Child[2] created with pid %d from parent with pid %d\n", getpid(), getppid());
	}

	else
	{
	pid3 = fork();
	if(pid3 == 0){
	printf("Child[1] created with pid %d from parent with pid %d\n", getpid(), getppid());
	}

	else{
	sleep(5);
	printf("No Child process created now, the parent process exist with pid %d\n", getppid());	
	}
	}
}	
}
	return 0;	
}
