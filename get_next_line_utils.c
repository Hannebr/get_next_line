/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 15:18:25 by hbrouwer      #+#    #+#                 */
/*   Updated: 2022/11/02 19:23:53 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	size_t	len;
	int		i;
	int		j;

	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	dest = (char *) malloc(len * sizeof(char));
	if (dest == NULL)
		return (free(s1), free(s2), NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = 0;
	free(s1);
	free(s2);
	return (dest);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < (size * count))
	{
		*((char *)ptr + i) = 0;
		i++;
	}
	return (ptr);
}
