/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csejault <csejault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 16:11:21 by csejault          #+#    #+#             */
/*   Updated: 2020/12/02 20:53:05 by csejault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* !!!!!!! STDIO !!!!!!!! */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#define DEBUG 0
typedef struct	s_gnl
{
	int		init;
	int		retreadf;
	char	*cache;
}				t_gnl;

int	get_next_line(int fd, char **line);
size_t  ft_strlen(const char *str);
char    *ft_strdup(const char *s);
char    *ft_substr(char const *s, unsigned int start, size_t len);
char    *ft_strjoin(char const *s1, char const *s2);
#endif
