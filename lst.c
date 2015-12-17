/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 17:46:35 by jgan              #+#    #+#             */
/*   Updated: 2015/12/04 23:14:11 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			build_lst(char *file, t_lst **start, int j)
{
	char	**tab;
	char	*line;
	int		fd;
	int		i;

	if (!(tab = (char **)malloc(sizeof(char *) * 4)))
		return (0);
	fd = open(file, O_RDONLY);
	while (j)
	{
		i = 0;
		while (i < 4)
		{
			ft_gnl(fd, &line);
			tab[i] = ft_strdup(line);
			++i;
		}
		if (!add_lst(start, tab))
			return (0);
		ft_gnl(fd, &line);
		--j;
	}
	close(fd);
	return (1);
}

static int	add_form(t_lst **tmp, char **tab)
{
	t_lst	*t;
	int		i;
	int		j;
	int		k;

	t = *tmp;
	i = -1;
	k = 0;
	while (++i < 4)
	{
		j = -1;
		while (tab[i][++j])
		{
			if (tab[i][j] == '#')
			{
				if (k == 4)
					return (0);
				t->form[k].x = i;
				t->form[k].y = j;
				++k;
			}
		}
	}
	return (k == 4 ? 1 : 0);
}

static int	check_form(t_lst **tmp)
{
	t_lst	*t;
	int		tot;
	int		i;

	t = *tmp;
	tot = 0;
	i = -1;
	while (++i < 4)
		tot = (tot * 10 + t->form[i].x) * 10 + t->form[i].y;
	if (tot == 10203 || tot == 10210 || tot == 10211 || tot == 10212
		|| tot == 11011 || tot == 11020 || tot == 11112 || tot == 11121
		|| tot == 101112 || tot == 101120 || tot == 101121 || tot == 102021
		|| tot == 102030 || tot == 1021011 || tot == 1101112 || tot == 1101120
		|| tot == 1101121 || tot == 1112021 || tot == 2101112)
		return (1);
	return (0);
}

static int	norm_form(t_lst **tmp)
{
	t_lst	*t;

	t = *tmp;
	while (t->form[0].x && t->form[1].x && t->form[2].x && t->form[3].x)
	{
		--(t->form[0].x);
		--(t->form[1].x);
		--(t->form[2].x);
		--(t->form[3].x);
	}
	while (t->form[0].y && t->form[1].y && t->form[2].y && t->form[3].y)
	{
		--(t->form[0].y);
		--(t->form[1].y);
		--(t->form[2].y);
		--(t->form[3].y);
	}
	return (check_form(tmp));
}

int			add_lst(t_lst **start, char **tab)
{
	t_lst	*tmp;
	t_lst	*new;

	tmp = *start;
	if (!(new = (t_lst *)malloc(sizeof(t_lst))))
		return (0);
	new->next = NULL;
	new->nb = 'A';
	new->form = (t_xy *)malloc(sizeof(t_xy) * 4);
	if (tmp)
	{
		++(new->nb);
		while (tmp->next)
		{
			tmp = tmp->next;
			++(new->nb);
		}
		tmp->next = new;
	}
	else
		*start = new;
	if (!add_form(&new, tab) || new->nb > 'Z')
		return (0);
	return (norm_form(&new) ? 1 : 0);
}
