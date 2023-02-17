#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <fcntl.h>
#include <pthread.h>

int	main(int argc, char	*argv[])
{
	int pid1 = fork();
	if (pid1 < 0){
		printf("Error creating process");
		return 1;
	}
	 if (pid1 == 0){
		sleep(4);
		printf("Finished execution (%d)\n", getpid());
		return 0;
	 }

	int pid2 = fork();
	if (pid2 < 0){
		printf("Error creating process");
		return 2;
	}
	if (pid2 == 0){
		sleep(1);
		printf("Finished execution (%d)\n", getpid());
		return 0;
	}
	int pid1_res = waitpid(pid1, NULL, 0);
	printf("Waited for %d\n", pid1_res);
	int pid2_res = waitpid(pid2, NULL, 0);
	printf("Waited for %d\n", pid2_res);
	return 0;
}
