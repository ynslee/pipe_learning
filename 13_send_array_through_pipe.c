
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
	if (pid == -1){
		return 1;
	}
	if (pid == 0){//child process
		close(fd[0]);
		int n;
		int i;
		int arr[10];
		srand(time(NULL));
		n = rand() % 10 + 1;
		printf("Generated: ");
		i = 0;
		while (i < n)
		{
			arr[i] = rand() % 11;
			i++;
			printf("%d", arr[i]);
		}
		printf("\n");
		if (write(fd[1], &n, sizeof(int)) < 0)
			return 4;
		printf("Sent n = %d\n", n);
		if (write(fd[1], arr, sizeof(int) * n) < 0)
			return 3;
		close(fd[1]);
	}else{//parent process
		close(fd[1]);
		int arr[10];
		int n, i, sum = 0;
		if (read(fd[0], &n, sizeof(int)) < 0)
			return 5;
		printf("Received n =%d\n", n);
		if (read(fd[0], arr, sizeof(int) * n) < 0)
			return 6;
		printf("Received array\n");
		close(fd[0]);
		while (i < n)
		{
			sum += arr[i];
			i++;
		}
		printf("Result is: %d\n", sum);
		wait(NULL);
	}
	return(0);
}