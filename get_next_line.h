/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 14:05:04 by hbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/31 20:24:35 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 128
#endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


char	*get_next_line(int fd);
int     ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*find_newline(char *line);

#endif