#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <fcntl.h>
#include <pthread.h>

//2 processes
// 1)child process should generate random numbers and send them to the parent
// 2)parent is going to sum all the numbers and print the result
// 3)child process has to send array
// 4)parent process has to read the array
int	main(int argc, char	*argv[])
{
	int fd[2];
	if (pipe(fd) == -1){
		return 1;
	}
	int pid1 = fork();
	if (pid1 < 0)
		return 2;
	 
	 if (pid1 == 0){
		//child process 1(ping)
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("ping", "ping", "-c", "5", "google.com", NULL);
	 }

	int pid2 = fork();
	if (pid2 < 0)
	 	return 3;
	if (pid2 == 0){
		//child process 2(grep)
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("grep", "grep", "rtt", NULL);
	}
	close(fd[0]);
	close(fd[1]);

	waitpid(pid1, NULL, 0);//wait for pid1 (this is used when you want to wait the child process individually)
	waitpid(pid2, NULL, 0);
	return 0;
}