/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:13:51 by yoonslee          #+#    #+#             */
/*   Updated: 2023/02/10 13:19:21 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int	main(int argc, char *argv[])
//{
	/* everything before the fork line is going to be executed once. but from fork
	line onwards, it will be processed twice. One is in the main process and the 
	other is in the child process.
	fork is like a child process - start executing the following line.
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

// int main(int argc, char* argv[])
// {
// 	int id =fork();
// 	if (id != 0){
// 	fork();
// 	}
// 	/* if you put fork function repeatedly, it will give you 2 to the power of n.
// 	Something like 2의 n승 */
// 	printf("Hello world\n");
// 	return 0;	
// }


