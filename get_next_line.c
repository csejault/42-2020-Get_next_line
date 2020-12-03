/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csejault <csejault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 16:20:45 by csejault          #+#    #+#             */
/*   Updated: 2020/12/02 20:56:34 by csejault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 ** For the bonus, we need to know the max file descriptor limit.
 ** I used the cmd --> ulimit -a <-- to find the max limit on our environment.
 ** On guacamole, it is 256.
 */

#include "get_next_line.h"

int		fill_line(char **line, t_gnl *gnl, size_t i, int flag_eof)
{
	char *tofree;
	size_t len;

	len = ft_strlen(gnl->cache);
	tofree = gnl->cache;
	if (!(*line = ft_substr(gnl->cache, 0, i++)))
		return (-1);
	if (flag_eof)
	{
		free(gnl->cache);
		gnl->cache = NULL;
		return (0);
	}
	len -= i;
	if(!(gnl->cache = ft_substr(gnl->cache, i, len)))
	{
		free(*line);
		return (-1);
	}
	free(tofree);
	return (1);
}

int		read_file(int fd, t_gnl *gnl)
{
	int		ret;
	char	*buf;
	char 	*tofree;
	
	tofree = gnl->cache;
	//{printf("Debut Read file\n");}
	if (!(buf = malloc(sizeof(*buf) * (BUFFER_SIZE + 1))))
	{
		//{printf("error malloa BUF\n");}
		return (-1);
	}
	if (0 > (ret = read(fd, buf, BUFFER_SIZE)))
	{
		//{printf("ret : %d, error malloc RET\n", ret);}
		free(buf);
		return (-1);
	}
	buf[ret] = '\0';
	if (gnl->cache)
	{
		gnl->cache = ft_strjoin(gnl->cache,buf);
		free(tofree);
	}
	else
		gnl->cache = ft_strdup(buf);
	free(buf);
	if (!gnl->cache)
		return (-1);
	//{printf("fin Read file avec str = %s\n", str[fd]);}
	return (ret);
}

int		read_cache(t_gnl *gnl, int fd, char **line)
{
	size_t			i;

	i = 0;
	while (gnl->cache[i])
	{
		if (gnl->cache[i] == '\n')
			return (fill_line(line, gnl, i, 0));
		else if (!gnl->retreadf && gnl->cache[i] == '\0')
			return (fill_line(line, gnl, i, 1));
		i++;
	}
	if (gnl->retreadf < 0)
		return (-1);
	return (gnl->retreadf = read_file(fd, gnl));
}

int	get_next_line(int fd, char **line)
{
	static t_gnl	gnl;
	int retcache;

	*line = NULL;
	retcache = 0;
	if (!gnl.retreadf && gnl.init == 1)
		return (-1);
	if (1 > BUFFER_SIZE)
		return (-1);
	if (!gnl.cache)
	{
		if (0 > (gnl.retreadf = read_file(fd, &gnl)))
			return (-1);
			gnl.init = 1;
	}
	while ((retcache = read_cache(&gnl, fd, line)))
		if (retcache > 0 && *line)
			return (1);
		else if (retcache < 0)
		{
			if (gnl.cache)
				free(gnl.cache);
			return (-1);
		}
	return (0);
}
