/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huygun <huygun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:39:17 by huygun            #+#    #+#             */
/*   Updated: 2023/07/31 14:12:02 by huygun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_new_all_lines(char *all_lines, size_t count)
{
	char	*new_line;

	while (all_lines[count] != '\n' && all_lines[count] != '\0')
		count++;
	if (!all_lines[count])
	{
		free(all_lines);
		return (NULL);
	}
	new_line = ft_substr(all_lines, count + 1, ft_strlen(all_lines) - count);
	free(all_lines);
	return (new_line);
}

char	*get_first_line(char *all_lines, int i)
{
	char	*p;

	if (!*all_lines)
		return (NULL);
	while (all_lines[i] && all_lines[i] != '\n')
		i++;
	p = malloc((i + 2) * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (all_lines[i] && all_lines[i] != '\n')
	{
		p[i] = all_lines[i];
		i++;
	}
	if (all_lines[i] == '\n')
	{
		p[i] = all_lines[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*get_read_line(int fd, char *all_lines, ssize_t read_bytes)
{
	char	*buff;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (!ft_strchr(all_lines, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			free(all_lines);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		all_lines = ft_strjoin_free(all_lines, buff, 0, 0);
	}
	free(buff);
	return (all_lines);
}

char	*get_next_line(int fd)
{
	static char	*all_lines;
	char		*first_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	all_lines = get_read_line(fd, all_lines, 1);
	if (!all_lines)
		return (NULL);
	first_line = get_first_line(all_lines, 0);
	all_lines = get_new_all_lines(all_lines, 0);
	return (first_line);
}
