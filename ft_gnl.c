/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 23:18:15 by jgan              #+#    #+#             */
/*   Updated: 2015/11/29 15:20:08 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**add_tmp(char **tmp, int fd)
{
	char	**new;
	int		i;

	new = (char **)malloc(sizeof(char *) * (fd + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (i <= fd)
	{
		if (tmp && tmp[i])
			new[i] = ft_strdup(tmp[i]);
		else
			new[i] = ft_strnew(0);
		++i;
	}
	new[i] = NULL;
	return (new);
}

int			ft_gnl(int fd, char **line)
{
	static char	**tmp = NULL;
	char		buf[BUFF_SIZE + 1];
	int			ret;
	int			i;

	if (fd < 0 || !line || read(fd, buf, 0))
		return (-1);
	if (!tmp || !tmp[fd])
		tmp = add_tmp(tmp, fd);
	while (!ft_strchr(tmp[fd], '\n') && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp[fd] = ft_strjoin(tmp[fd], buf);
	}
	i = 0;
	while (tmp[fd][i] && tmp[fd][i] != '\n')
		++i;
	*line = ft_strndup(tmp[fd], i);
	tmp[fd] = ft_strdup(tmp[fd][i] ? tmp[fd] + i + 1 : tmp[fd] + i);
	return (ret ? 1 : 0);
}
/*
** Moulitest doesnt want my frees
**line : "lines written"
**27 :	"free(&tmp[i]);"
**32 :	"if (tmp)
**		free(tmp);"
**35 :	"there was a strjoin with free(s1) before return"
**39 :	"char		*noleaks;"
**55 :	"instead of 'tmp[fd] =', 'noleaks ='"
**		"free(tmp[fd]);
**		tmp[fd] = noleaks;
**		if (!ret)
**			free(tmp[fd]);"
*/
