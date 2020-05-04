#include<stdio.h>
#include<stdlib.h> 
int getpid();
int getppid();
int fork();
void wait();
int main() 
{ 
	for(int i=0;i<1;i++) 
	{ 
		if(fork() == 0) 
		{ 
			printf("[child] pid is %d created from [parent] pid %d\n", getpid(), getppid()); 
			exit(0); 
		} 
	} 
	for(int i=0;i<1;i++) 
	wait(NULL); 

	/*int check = fork();
	if(check == 0)
	printf("child created\n");
	else
	printf("firstly child is not created");*/
} 


