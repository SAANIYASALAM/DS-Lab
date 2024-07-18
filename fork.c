#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
	int pid;
	pid = fork();
	if (pid<0)
	{
		printf("fork failed");
		exit(1);
	}
	else if (pid==0)
	{
		printf("the child process id is %d", getpid());
		exit(0);
	}
	else
	{
		printf("the parent process id is %d",getpid());
		wait(NULL);
	}
	return 0;
}

