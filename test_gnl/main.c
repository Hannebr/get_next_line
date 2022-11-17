/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/17 15:05:37 by hbrouwer      #+#    #+#                 */
/*   Updated: 2022/11/17 15:06:19 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(void)
{
	int fd = open("test.txt", O_RDONLY);
    int i = 0;
    while (i < 7)
    {
        char *str = get_next_line(fd);
        printf("%s", str);
        free(str);
        i++;
    }
}