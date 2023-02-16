
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
		return (1); // exit(1) is the same thing.
	if (pid == 0)//child process
	{	
		int	file = open("pingResults.txt", O_WRONLY | O_CREAT, 0777);
		if (file == -1)
			return (2);
		/*To get stdoutput to file, you use 'dup'. This will create another 
		file descriptor, in this case 4, and then copy the file into it.*/
		dup2(file, STDOUT_FILENO); 
		/*with dup2, you also get the similar action as 'dup', but it takes
		two parameters. first one is the one that we want to copy and second one
		is the value that we want to give as file descriptor, for example 1(STDOUT)
		But it is better to use it as STDOUD_FILENO because it is c standard.*/
		close(file);
		int	err = execlp("ping", "ping", "-c", "3", "google.com", NULL); //try with google.con
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