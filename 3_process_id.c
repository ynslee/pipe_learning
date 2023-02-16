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
	/*getpid is to get the process id for our current process that is happening.
	getpid does not take any parameters.
	we get two different ids for main process and child process. 
	Another we can do is get parent process id.
	*/

// int	main(int argc, char	**argv)
// {
// 	int	id = fork();
// 	if (id == 0)
// 		sleep(1);
// 	printf("Current ID : %d\n, parent ID: %d\n", getpid(), getppid());
// 	return (0);
// }

/*In the pervious fork_wait file, we talked about wait() in process. 
Normally, parent process waits for the child process. Always child process should terminates
first before parent process terminates. sleep(1 <- this means sleep for 1 second)
we are still having child process running till the parent process starts
it got assigned to new parent id.

If you terminate the parent process first before child process, something weird happens
and it is called as zombie process. This can cause a leak.
*/

// int	main(int argc, char	**argv)
// {
// 	int	id = fork();
// 	if (id == 0)
// 		sleep(1);
// 	printf("Current ID : %d\n, parent ID: %d\n", getpid(), getppid());
// 	if (id != 0)
// 		wait(NULL);
// 	return (0);
// }
/* the fork function we are using is to wait till parent process finishes to move on 
to child process. you can also do it wihtout checking if it is parent. Because if it
is not parent, it is still going to finish the program accordingly.
*/

int	main(int argc, char	**argv)
{
	int	id = fork();
	if (id == 0)
		sleep(1);
	printf("Current ID : %d\n, parent ID: %d\n", getpid(), getppid());
	
	int res = wait(NULL);
	if (res == -1)
		printf("No children to wait for\n");
	else
		printf("%d finished execution\n", res);
	return (0);
}
/* Wait function is gonna check if there is any child processes to wait for. if
there is no child process to wait for, it is going to return -1. Wait call return
something useful if it is not an error.
you get the process ID that you were waiting for. This is useful if you have a lot
of chile process that is going on*/