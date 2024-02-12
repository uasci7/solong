/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saksoy <saksoy@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:41:12 by saksoy            #+#    #+#             */
/*   Updated: 2022/03/23 16:33:17 by saksoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30
# endif

char	*get_next_line(int fd);
char	*f_strchr(const char *str, int c);
char	*f_strjoin(char *s1, char *s2);
size_t	f_strlen(const char *str);
char	*f_strdup(const char *s1);
char	*f_substr(char *s, unsigned int start, size_t len);
char	*strappend(char **str, char *str2);
char	*get_data(char **backup, int fd);
#endif