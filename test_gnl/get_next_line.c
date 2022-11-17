/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/17 12:43:21 by hbrouwer      #+#    #+#                 */
/*   Updated: 2022/11/17 15:46:24 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
	static char	*buffer;
	char 		*line;

	buffer = read_file(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	line = trim_line(buffer);
	if (line == NULL)
		return (NULL);
	buffer = move_buff(buffer);
	return (line);
}

char	*read_file(int fd, char *buff_line)
{
	char	*buffer;
	int		read_bytes;

	if (buff_line == NULL)
	{
		buff_line = (char *) ft_calloc(1, sizeof(char));
		if (buff_line == NULL)
			return (NULL);
	}
	buffer = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buffer == NULL)
		return (free(buff_line), NULL);
	read_bytes = 1;
	while (read_bytes > 0 && !(ft_strchr(buffer, '\n')))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
			return (free(buffer), free(buff_line), NULL);
		buffer[read_bytes] = 0;
		buff_line = free_and_join(buff_line, buffer);
		if (buff_line == NULL)
			return (free(buffer), NULL);
	}
	return (free(buffer), buff_line);
}

char	*free_and_join(char *total_buff, char *sub_buff)
{
	char	*joined_buff;
	
	joined_buff = ft_strjoin(total_buff, sub_buff);
	if (joined_buff == NULL)
		return (free(total_buff), NULL);
	return(free(total_buff), joined_buff);
}

char	*trim_line(char *buffer)
{
	int		len;
	int		i;
	char	*result;

	len = 0;
	while (buffer[len] != '\n' && buffer[len] != '\0')
		len++;
	if (buffer[len] == '\0')
		return (ft_strdup(buffer));
	result = (char *) ft_calloc((len + 2), sizeof(char));
	if (result == NULL)
		return (free(buffer), NULL);
	i = 0;
	while (i <= len)
	{
		result[i] = buffer[i];
		i++;
	}
	return (result);
}

char	*move_buff(char *buffer)
{
	int		len;
	int		i;
	char	*new_buff;

	len = 0;
	while (buffer[len] != '\n' && buffer[len] != '\0')
		len++;
	if (buffer[len] == '\0')
		return (free(buffer), NULL);
	len++;
	new_buff = (char *) ft_calloc((ft_strlen(buffer) - len + 1), sizeof(char));
	if (new_buff == NULL)
		return (NULL);
	i = 0;
	while (buffer[len + i])
	{
		new_buff[i] = buffer[len + i];
		i++;
	}
	return (free(buffer), new_buff);
}