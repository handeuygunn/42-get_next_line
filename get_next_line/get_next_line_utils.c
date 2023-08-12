/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huygun <huygun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:24:19 by huygun            #+#    #+#             */
/*   Updated: 2023/07/29 18:29:45 by huygun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	i = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	p = (char *) malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (i < ft_strlen(s) && i < len && s[start + i])
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = 0;
	return (p);
}

size_t	ft_strlen(const char *s)
{
	int	length;

	length = 0;
	while (s[length])
	{
		length++;
	}
	return (length);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin_free(char *all_lines, char *buff, size_t i, size_t j)
{
	char	*str;

	if (!all_lines)
	{
		all_lines = (char *)malloc(1 * sizeof(char));
		all_lines[0] = '\0';
	}
	str = malloc(sizeof(char) * ((ft_strlen(all_lines) + ft_strlen(buff)) + 1));
	if (!str)
		return (NULL);
	while (all_lines[i] != '\0')
	{
		str[i] = all_lines[i];
		i++;
	}
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(all_lines) + ft_strlen(buff)] = '\0';
	free(all_lines);
	return (str);
}
