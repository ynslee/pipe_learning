
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(int argc, char	*argv[])
{
	char *arr[] = {"ping", "google.com", NULL};
	_execvp(//v is for the vector, for array. e is environment
		"ping",
		arr,
		);
	return 0;
}