/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csejault <csejault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 15:42:56 by csejault          #+#    #+#             */
/*   Updated: 2020/12/09 11:36:52 by csejault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*ret;

	len = ft_strlen(s);
	if (!(ret = malloc(sizeof(*ret) * (len + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*retour;

	i = 0;
	retour = NULL;
	if (!s)
		return (NULL);
	if (!(retour = malloc(sizeof(*s) * (len + 1))))
		return (NULL);
	retour[i] = '\0';
	while (i < start)
	{
		if (!s[i])
			return (retour);
		i++;
	}
	i = 0;
	while (i < len && s[start + i])
	{
		retour[i] = s[start + i];
		i++;
	}
	retour[i] = '\0';
	return (retour);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	int		j;
	char	*ret;

	ret = NULL;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	if (!(ret = malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = -1;
	while (s1[++i])
		ret[i] = s1[i];
	j = -1;
	while (s2[++j])
		ret[i + j] = s2[j];
	ret[i + j] = 0;
	return (ret);
}
