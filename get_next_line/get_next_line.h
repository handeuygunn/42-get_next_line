/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huygun <huygun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:39:20 by huygun            #+#    #+#             */
/*   Updated: 2023/07/30 10:28:41 by huygun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*get_read_line(int fd, char *all_lines, ssize_t read_bytes);
char	*get_new_all_lines(char *all_lines, size_t count);
char	*ft_strjoin_free(char *line, char *buff, size_t i, size_t j);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *s1);
char	*ft_strchr(char *s, int c);
char	*get_first_line(char *all_lines, int i);

#endif
