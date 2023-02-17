
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <fcntl.h>

int	main(int argc, char	*argv[])
{
	int pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{	
		int	file = open("pingResults.txt", O_WRONLY | O_CREAT, 0777);
		if (file == -1)
			return (2);
		dup2(file, STDOUT_FILENO); 
		close(file);
		int	err = execlp("ping", "ping", "-c", "3", "google.com", "|", 
		"grep", "\"rtt\"", NULL); //execlp only does the executable so this wouldn't work.
		if (err == -1){
			printf("Could not find proram to execute!\n");
			return (2);
		}
	}
	else
	{
		int wstatus;
		wait(&wstatus);
		if (WIFEXITED(wstatus))
		{
			int statuscode = WEXITSTATUS(wstatus);
			if (statuscode == 0)
				printf("success!\n");
			else
				printf("failure with the status code %d\n", statuscode);
		}
	}
	return (0);
}