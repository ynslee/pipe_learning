
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>

int	main(int argc, char	*argv[])
{
	int pid = fork();
	if (pid == -1)
		return (1); // exit(1) is the same thing.
	if (pid == 0)//child process
	{	int err = execlp("ping", "ping", "-c", "3", "google.com", NULL); //try with google.con
		if (err == -1){
			printf("Could not find proram to execute!\n");
			return (2);
		}
	}
	else//parent process
	{
		int wstatus;
		wait(&wstatus);
		if (WIFEXITED(wstatus))//to check if the process is processed normally
		{
			int statuscode = WEXITSTATUS(wstatus); //return value inside the main.
			if (statuscode == 0)
				printf("success!\n");
			else
				printf("failure with the status code %d\n", statuscode);
		}
	}
	return (0);
}