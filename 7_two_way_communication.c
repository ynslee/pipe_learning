
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/pipe.h>
#include <sys/wait.h>
#include <time.h>

// int	main(int argc, char	*argv[])
// {
// /*two way communications between parent and child. let's say generate number from
// 0 to 5.
// let's say 5 is sent to other process and other process multiplies it by four. then
// sent to original program the result.
// 5 => 5 * 4 = 20 => 20
// How to do it? first, create the pipe.*/
// 	int p1[2];
// 	if (pipe(p1) == -1)
// 		return 1;
// 	int pid = fork();
// 	if (pid == -1)
// 		return 2;
// 	if (pid == 0)//child process. we want to read the data from parent process
// 	{
// 		int x;
// 		if (read(p1[0], &x, sizeof(x)) == -1)
// 			return 3;
// 		printf("Received %d\n", x);
// 		x = x * 4;
// 		if (write(p1[1], &x, sizeof(x)) == -1)
// 			return 4;
// 		printf("Wrote %d\n", x);
// 	} else {//parent process
// 		srand(time(NULL));
// 		int y = rand() % 10;
// 		if (write(p1[1], &y, sizeof(y)) == -1)
// 			return 5;
// 		printf("Wrote %d\n", y);
// 		if (read(p1[0], &y, sizeof(y)) == -1)
// 			return 6;
// 		printf("Result is %d\n", y);
// 		wait(NULL);
// 	}
// 	close(p1[0]);
// 	close(p1[1]);
// 	return 0;
// }

/*we cannot have a pipe that both sends data and receives data on the same process.
we need to have two pipes in order to achieve the solution and make it work*/

int	main(int argc, char	*argv[])
{
	int p1[2]; //let's say p1 is going from child to parent
	int p2[2]; // p => c. write and send data to a child.
	if (pipe(p1) == -1)
		return 1;
	if (pipe(p2) == -1)
		return 1;
	int pid = fork();
	if (pid == -1)
		return 2;
	if (pid == 0)//child process. we want to read the data from parent process
	{
		close(p1[0]);//p1, it is child to parent and it only writes. it does not need to read.
		close(p2[1]);//child process does not write anything to it.
		int x;
		if (read(p2[0], &x, sizeof(x)) == -1)
			return 3;
		printf("Received %d\n", x);
		x = x * 4;
		if (write(p1[1], &x, sizeof(x)) == -1)
			return 4;
		printf("Wrote %d\n", x);
		close(p1[1]);
		close(p2[0]);
	} else {//parent process
		close(p1[1]);
		close(p2[0]);
		srand(time(NULL));
		int y = rand() % 10;
		if (write(p2[1], &y, sizeof(y)) == -1)//writes data to child process
			return 5;
		printf("Wrote %d\n", y);
		if (read(p1[0], &y, sizeof(y)) == -1)//read data from child process
			return 6;
		printf("Result is %d\n", y);
		close(p1[0]);
		close(p2[1]);
		wait(NULL);
	}
	return 0;
}