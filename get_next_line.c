/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 14:04:16 by hbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/31 20:25:25 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	char		*current_line;
	char		*next_line;
	

	line = (char *) malloc(BUFFER_SIZE * sizeof(char));
	if (line == NULL)
		return (NULL);
	read(fd, line, BUFFER_SIZE);
	next_line = find_newline(line);
	while (1)
	{
		if (ft_strlen(next_line) < BUFFER_SIZE)
			return (next_line);
		else
		{
			line = ft_strjoin(line, next_line);
			current_line = (char *) malloc(BUFFER_SIZE * sizeof(char));
			read(fd, current_line, BUFFER_SIZE);
			next_line = find_newline(current_line);
		}
	}
}

char	*find_newline(char *line)
{
	static int    read_bytes;
	int            i;
	char          *str;
	int           j;
	
	i = read_bytes;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	str = (char *) malloc((i - read_bytes + 1) * sizeof(char));
	j = 0;
	while (read_bytes < i)
	{
		str[j] = line[read_bytes];
		j++;
		read_bytes++;
	}
	free(line);
	str[j] = 0;
	read_bytes++;
	return (str);
}