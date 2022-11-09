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
#include <limits.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*next_line;
	static int	line_len;

	if (fd < 0 || fd > OPEN_MAX || read(fd, buffer, 0) < 0)
		return (NULL);
	line = NULL;
	while (1)
	{
		if (buffer_is_empty(buffer))
		{
			line_len = read(fd, buffer, BUFFER_SIZE);
			if (line_len <= 0)
				return (reset_buffer(buffer), free(line), NULL);
			line_len = 0;
		}
		next_line = find_newline(buffer, &line_len);
		line = ft_strjoin(line, next_line);
		if (line == NULL)
			return (reset_buffer(buffer), NULL);
		if (line_len < BUFFER_SIZE)
		{
			line_len++;
			return (line);
		}
		else
			reset_buffer(&buffer[0]);
	}
}

char	*find_newline(char *line, int *line_len)
{
	int		i;
	char	*str;
	int		j;

	i = *line_len;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	str = (char *) ft_calloc((i - *line_len + 2), sizeof(char));
	if (str == NULL)
		return (NULL);
	j = 0;
	while (*line_len < i)
	{
		str[j] = line[*line_len];
		j++;
		(*line_len)++;
	}
	if (line[*line_len] == '\n')
	{
		str[j] = line[*line_len];
	}
	return (str);
}

int	buffer_is_empty(char *buffer)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE + 1)
	{
		if (buffer[i] != 0)
			return (0);
		i++;
	}
	return (1);
}

void	reset_buffer(char *buffer)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE + 1)
	{
		buffer[i] = 0;
		i++;
	}
}
