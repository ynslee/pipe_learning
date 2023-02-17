
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <fcntl.h>

//2 processes
// 1)child process should generate random numbers and send them to the parent
// 2)parent is going to sum all the numbers and print the result
// 3)child process has to send array
// 4)parent process has to read the array
int	main(int argc, char	*argv[])
{
	int fd[2];
	if (pipe(fd) == -1)
		printf("pipe error!\n");
	int pid = fork();
	if (pid < 0){
		return 1;
	}
	if (pid == 0){//child process
		close(fd[0]);
		char str[200];
		printf("Input string: ");
		fgets(str, 200, stdin);// this will end with the new line so you replace with null terminator
		str[strlen(str) - 1] = '\0';
		int n = strlen(str) + 1;
		if (write(fd[1], &n, sizeof(int)) < 0)
			return 4;
		printf("\n");
		if (write(fd[1], str, sizeof(char) * n) < 0)
			return 3;
		close(fd[1]);
	}else{//parent process
		close(fd[1]);
		char str[200];
		int	n;
		if (read(fd[0], &n, sizeof(int)) < 0)
			return 5;
		if (read(fd[0], str, sizeof(char) * n) < 0)
			return 6;
		printf("Received: %s\n", str);
		close(fd[0]);
		wait(NULL);
	}
	return(0);
}