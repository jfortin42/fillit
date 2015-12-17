/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 00:12:01 by jgan              #+#    #+#             */
/*   Updated: 2015/12/04 23:14:00 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int ac, char **av)
{
	t_lst	*start;
	int		j;

	start = NULL;
	if (av[1] && ac == 2 && (j = check_file(av[1]))
		&& build_lst(av[1], &start, j))
		do_lst(&start, j);
	else
		ft_putendl("error");
	return (0);
}

static int	check_char(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (!(line[i] == '.' || line[i] == '#'))
			return (0);
		i++;
	}
	return (1);
}

int			check_file(char *file)
{
	char	*line;
	int		fd;
	int		i;
	int		j;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	j = 0;
	i = 0;
	while (ft_gnl(fd, &line))
	{
		if (i == 4)
		{
			if (ft_strlen(line))
				return (0);
			++j;
			i = -1;
		}
		else if (ft_strlen(line) != 4 || !check_char(line))
			return (0);
		++i;
	}
	++j;
	close(fd);
	return (i == 4 ? j : 0);
}

int			ft_square(int j)
{
	int	i;

	i = 0;
	while (i * i < j)
		i++;
	return (i);
}
