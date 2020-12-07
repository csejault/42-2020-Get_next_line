/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csejault <csejault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 16:20:45 by csejault          #+#    #+#             */
/*   Updated: 2020/12/07 15:48:03 by csejault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 ** For the bonus, we need to know the max file descriptor limit.
 ** I used the cmd --> ulimit -a <-- to find the max limit on our environment.
 ** On guacamole, it is 256.
 */

#include "get_next_line.h"

int		fill_line(char **line, t_gnl *gnl, size_t i)
{
	char	*tofree;
	size_t	len;

	len = ft_strlen(gnl->cache);
	tofree = gnl->cache;
	if (!(*line = ft_substr(gnl->cache, 0, i++)))
		return (-1);
	if (!gnl->cache[i] && gnl->retreadf < BUFFER_SIZE)
	{
		free(gnl->cache);
		gnl->cache = NULL;
		return (0);
	}
	len -= i;
	if (!(gnl->cache = ft_substr(gnl->cache, i, len)))
	{
		free(*line);
		return (-1);
	}
	free(tofree);
	return (1);
}

int		read_file(int fd, t_gnl *gnl)
{
	char	*buf;
	char	*tofree;

	tofree = gnl->cache;
	if (!(buf = malloc(sizeof(*buf) * (BUFFER_SIZE + 1))))
		return (gnl->retreadf = -1);
	if (0 > (gnl->retreadf = read(fd, buf, BUFFER_SIZE)))
	{
		free(buf);
		return (gnl->retreadf);
	}
	buf[gnl->retreadf] = '\0';
	if (gnl->cache)
	{
		gnl->cache = ft_strjoin(gnl->cache, buf);
		free(tofree);
	}
	else
		gnl->cache = ft_strdup(buf);
	free(buf);
	if (!gnl->cache)
		return (gnl->retreadf = -1);
	return (gnl->retreadf);
}

int		read_cache(t_gnl *gnl, int fd, char **line)
{
	size_t	i;
	int		ret;

	ret = 0;
	i = 0;
	while (gnl->cache[i] && gnl->cache[i] != '\n')
		i++;
	if (gnl->cache[i] == '\n')
		return (ret = fill_line(line, gnl, i));
	else if (gnl->cache[i] == '\0')
	{
		if (gnl->retreadf < BUFFER_SIZE) 
			return (fill_line(line, gnl, i));
		else if (0 > (read_file(fd, gnl)))
			return (-1);
		else
			return (read_cache(gnl, fd, line));
	}
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	static t_gnl	gnl;
	int				retcache;

	*line = NULL;
	retcache = 0;
	if (1 > BUFFER_SIZE || !line)
		return (-1);
	if (!gnl.cache)
	{
		//if (gnl.init == 1 && gnl.retreadf < BUFFER_SIZE)
		//{
		//	if (!(*line = malloc(sizeof(**line) * 20)))
		//		return (-1);
		//	*line[0] = '\0';
		//	return (0);
		//}
		if (0 > read_file(fd, &gnl))
			return (-1);
		gnl.init = 1;
	}
	if( 0 > (retcache = read_cache(&gnl, fd, line))) 
	{
		if (gnl.cache)
			free(gnl.cache);
		return (-1);
	}
	else
		return (retcache);
	return (0);
}
