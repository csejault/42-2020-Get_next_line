/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csejault <csejault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 16:20:45 by csejault          #+#    #+#             */
/*   Updated: 2020/11/29 14:02:00 by csejault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** For the bonus, we need to know the max file descriptor limit.
** I used the cmd --> ulimit -a <-- to find the max limit on our environment.
** On guacamole, it is 256.
*/

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	long	alrd_r[256];
	char	*string;

	string = NULL;
	if (1 > BUFFER_SIZE)
		return (-1);
	if (!(string = malloc(sizeof(*string) * (BUFFER_SIZE + 1))))
		return (-1);
	if (0 > (alrd_r[fd] = read(fd, string, BUFFER_SIZE)))
	{
		free(string);
		return (-1);
	}
	string[alrd_r[fd]] = '\0';
	*line = string;
	return (0);
}
