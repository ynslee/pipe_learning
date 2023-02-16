
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>

// int	main(int argc, char	*argv[])
// {
// 	execlp("ping", "ping", "-c", "3", "google.com", NULL);
// 	printf("Success!\n");
// 	return 0;
// }
//execlp function of what they do? they replace the whole process so all the memory 
//will be replace by its own memory. execution line will be replaced by its own line
//you can not call execlp on the parent process because child process then will become zombie & memory leaks.
int	main(int argc, char	*argv[])
{
	int pid = fork();
	if (pid == -1)
		return 1;
	if (pid == 0)//child process
		execlp("ping", "ping", "-c", "3", "google.com", NULL);
	else//parent process
	{
		wait(NULL);
		printf("Success!\n");
	}
	return 0;
}