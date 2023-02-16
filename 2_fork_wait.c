#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*wait for fork process to finish*/

// int	main(int argc, char	**argv)
// {
// 	int	id = fork();
// 	int	n;
// 	int	i;

// 	if (id == 0)
// 		n = 1;
// 	else
// 		n = 6;
// 	i = n;
// 	while (i < n + 5)
// 	{
// 		printf("%d", i);
// 		fflush(stdout);
// 		i++;
// 	}
// 	printf("\n");
// 	return (0);
// }

/*to get the proper out put that I want (1 - 10 printed out,
need to flush stdouput. stdoutput of printf has internal buffer
it is gonna wait the entier process and will print out together.
In this case, I want to print them all exactly when I call printf.
Therefore use fflush. It is unpredictable so you can not be sure about order.
they are completely chaotic.

So then, the wait function comes in. It comes in so that the we can tell the main
process to wait for the child process to be done and then print the number after
child process.*/

int	main(int argc, char	**argv)
{
	int	id = fork();
	int	n;
	int	i;

	if (id == 0)
		n = 1;
	else
		n = 6;
	if (id != 0)
		wait(1);//need question for this
	i = n;
	while (i < n + 5)
	{
		printf("%d", i);
		fflush(stdout);
		i++;
	}
	if (id != 0)
		printf("\n");
	return (0);
}
	/*this function shows that if it is not child process, you wait till 
	the child process finishes.*/