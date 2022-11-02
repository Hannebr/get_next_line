/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 14:04:16 by hbrouwer      #+#    #+#                 */
/*   Updated: 2022/11/02 19:43:42 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	static char	*line;
	char		*next_line;
	static int	line_len;

	if (fd == -1)
		return (NULL);
	line = NULL;
	if (!buffer)
	{
		buffer = (char *) ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		if (buffer == NULL)
			return (NULL);
		read(fd, buffer, BUFFER_SIZE);			
		line_len = 0;
	}
	next_line = find_newline(buffer, &line_len);
	while (1)
	{
		line = ft_strjoin(line, next_line);
		if (line_len < BUFFER_SIZE)
		{
			line_len++;
			return (line);
		}
		else
		{
			buffer = (char *) ft_calloc((BUFFER_SIZE + 1), sizeof(char));
			if (buffer == NULL)
				return (NULL);
			read(fd, buffer, BUFFER_SIZE);
			line_len = 0;
			next_line = find_newline(buffer, &line_len);
		}
	}
}

char	*find_newline(char *line, int *line_len)
{
	int            i;
	char          *str;
	int           j;
	
	i = *line_len;
	while (!(line[i] == '\n' || line[i] == '\0'))
		i++;
	str = (char *) ft_calloc((i - *line_len + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	j = 0;
	while (*line_len < i)
	{
		str[j] = line[*line_len];
		j++;
		(*line_len)++;
	}
	if (j == BUFFER_SIZE)
		free(line);
	return (str);
}