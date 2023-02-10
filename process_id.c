#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

/* what are process IDs? IDs for processes in Linux. every single process has an id.
number that is uniques for that process. To get the id, you need to have #include <sys/wait.h>

*/

// int	main(int argc, char	**argv)
// {
// 	int	id = fork();
// 	printf("%d\n", getpid());
// 	return (0);
// }
	/*getpid is to get the id for our current process that is happening.
	getpid does not take any parameters.
	we get two different ids for main process and child process. 
	Another we can do is get parent process id.
	*/

int	main(int argc, char	**argv)
{
	int	id = fork();
	if (id == 0)
		sleep(1);
	printf("Current ID : %d\n, parent ID: %d\n", getpid(), getppid());
	return (0);
}

/*In the pervious fork_wait file, we talked about wait() in process. Normally,
parent process waits for the child process. Always child process should terminates
first before parent process terminates. sleep(1 <- this means sleep for 1 second)
If you terminate the parent process first before child process, something weird happens
and it is called as zombie process*/