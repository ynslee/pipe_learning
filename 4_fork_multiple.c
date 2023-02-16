#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

int	main(int argc, char	**argv)
{
	int	id1 = fork();
	int id2 = fork();
	// while (wait(NULL) != -1 || errno != ECHILD)
	// 	printf("Waited for a child to finish\n");
	if (id1 == 0){
		if (id2 == 0)
			printf("we are process y\n");
		else
			printf("we are process x\n");
	}else{
		if (id2 == 0)
			printf("we are process z\n");
		else
			printf("we are the parent process!\n");
	}
	//wait(NULL);//if you have two forks, if you just use wait(NULL),it won't work.
	while (wait(NULL) != -1 || errno != ECHILD)
		printf("Waited for a child to finish\n"); //until there will be no child process, it will continue
	return (0);
}

/*if you call fork once, you will get another process but if you do it again, 
an other arrow will get drawn to both processes. 
if you have both id1 = 0 and id2 = 0, you are certainly the child of another child
of the process. check the notes that explains the process in diagram
if you have two forks, if you just use wait(NULL)
if you write something like for(int i = 0; i < 10; i++) this is not making 10 process,
this makes 10times of 2 processes.(2*2*2*....)*/