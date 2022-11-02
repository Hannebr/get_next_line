/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 14:46:12 by hbrouwer      #+#    #+#                 */
/*   Updated: 2022/11/02 19:23:30 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #ifndef BUFFER_SIZE
// # define BUFFER_SIZE 1000
// #endif

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

void check_leaks();

int	main(void)
{
	int fd = open("test.txt", O_RDONLY);
    int i = 0;
    while (i < 3)
    {
        char *str = get_next_line(fd);
        printf("%s\n", str);
        i++;
    }
}