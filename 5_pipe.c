
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

int	main(int argc, char	**argv)
{
	int	fd[2];
	//two ends of pipes are stored here. it includes
	//fd[0] read
	//fd[1] write
	if (pipe(fd) == -1){
		printf("An error occured with opening th epipe\n");
		return 1;
	}
	int id = fork();
	if (id ==-1){
		printf("An error occured with opening th epipe\n");
		return 4;
	}
	if (id == 0) //ask user to input a number and sends it to parent process from child process
	{
		close(fd[0]);
		int x;
		printf("input a number: ");
		scanf("%d", &x);
		if (write(fd[1], &x, sizeof(int)) == -1){//code for the child process
			printf("An error occured with writing to the pipe\n");
			return 2;
		}
		close(fd[1]);
	}else{
		close(fd[1]);
		int y;
		if (read(fd[0], &y, sizeof(int)) == -1){;//code for the parent process. got actuallly written to the pipe(&x)
			printf("An error occured with reading to the pipe\n");
			return 3;
		}
		y = y * 3;
		close(fd[0]);
		printf("God from child process %d\n", y);
		wait(NULL);
	}

	return (0);
}
/*sent over to another process. pipe function is something you can think as memory
file. it's a file only has sort of a buffer that is saved in a memory and you can
write and read from it. If we want to open a pipe, we call the pipe with the file
descripter. fd shows where we want to either read or write data to.
pipe returns 0 if it is successful, -1 if it is not.

After you have opened the pipe, now we can fork. 
why only in this order? When you fork, the fd is get copied over. These fd are 
getting copied over but also assigned to the newly created process. they get
inherited. if you close the file descripter at one point in the process, that file 
descripter in the other process remains open. So fd will be copied and inherited so
it will be used as independantly*/