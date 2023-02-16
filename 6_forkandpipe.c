
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

int	main(int argc, char	*argv[])
{
	int arr[] = {1, 2, 3, 4, 1, 2, 7};
	int start;
	int end;
	int arrSize = sizeof(arr)/ sizeof(int);
	int fd[2];
	if (pipe(fd) == -1)
		return 1;
	
	int id = fork();
	if (id == -1)
		return 2;
	if (id == 0){//they are executed parallel not one after the other.
		start = 0;
		end = arrSize / 2;
	}else{
		start = arrSize / 2;
		end = arrSize;
	}
	int sum = 0;
	int i;
	i = start;
	while (i < end){
		sum += arr[i];
		i++;
	}

	printf("Calculated partial sum: %d\n", sum);
	if (id == 0){
		close(fd[0]);
		if (write(fd[1], &sum, sizeof(sum)) == -1)//always good to do error checking
			return 3;
		close(fd[1]);
	}else{
		int sumfromchild;
		close(fd[1]);
		if (read(fd[0], &sumfromchild, sizeof(sumfromchild)) == -1)
			return 4;
		close(fd[0]);
		int totalsum = sum + sumfromchild;
		printf("total sum is %d\n", totalsum);
		wait(NULL);
	}

	return 0;
}
