/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:13:51 by yoonslee          #+#    #+#             */
/*   Updated: 2023/02/09 16:19:42 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int	main(int argc, char *argv[])
//{
	/* fork is like a child process - start executing the following line.
	it executes alongside the main process
	id in the child process is always going to be zero. if id is not zero, it is main process.
	*/
	//int	id = fork();
	//printf("Hello world from id: %d\n", id);
	//if (id == 0)
	//	printf("Hello from child process\n");
	//else
	//	printf("Hello from the main process\n");
	//return 0;
//}

int main(int argc, char* argv[])
{
	fork();
	fork();
	printf("Hello world\n");
	return 0;	
}