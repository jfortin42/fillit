/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 20:58:32 by jgan              #+#    #+#             */
/*   Updated: 2015/12/08 23:32:06 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	place_form(t_xy pos, t_lst *tmp, char **tab)
{
	int		k;

	k = 0;
	while (k < 4 && tab[pos.x + tmp->form[k].x])
	{
		if (tab[pos.x + tmp->form[k].x][pos.y + tmp->form[k].y] != '.')
			break ;
		++k;
	}
	if (k == 4)
	{
		k = 0;
		while (k < 4)
		{
			tab[pos.x + tmp->form[k].x][pos.y + tmp->form[k].y] = tmp->nb;
			++k;
		}
		return (1);
	}
	return (0);
}

static void	init_tab(char ***tab, int max)
{
	char	**ret;
	int		i;
	int		j;

	if (!(ret = (char **)malloc(sizeof(char *) * (max + 1))))
		return ;
	i = 0;
	while (i < max)
	{
		if (!(ret[i] = (char *)malloc(sizeof(char) * (max + 1))))
			return ;
		j = 0;
		while (j < max)
		{
			ret[i][j] = '.';
			++j;
		}
		ret[i][j] = '\0';
		++i;
	}
	ret[i] = NULL;
	*tab = ret;
}

static void	del_form(t_lst *tmp, char **tab, int max)
{
	t_xy	pos2;
	int		i;

	i = 0;
	pos2.x = -1;
	while (++(pos2.x) < max)
	{
		pos2.y = -1;
		while (++(pos2.y) < max)
			if (tab[pos2.x][pos2.y] == tmp->nb)
			{
				tab[pos2.x][pos2.y] = '.';
				++i;
				if (i == 4)
					return ;
			}
	}
}

static int	find_square(t_lst *tmp, char **tab, int max)
{
	t_xy	pos;

	if (!tmp)
	{
		ft_putstrtab(tab, "\n");
		return (1);
	}
	pos.x = 0;
	pos.y = 0;
	while (pos.x < max)
	{
		if (place_form(pos, tmp, tab))
			if (find_square(tmp->next, tab, max))
				return (1);
		del_form(tmp, tab, max);
		if (++(pos.y) == max)
		{
			pos.y = 0;
			++(pos.x);
		}
	}
	return (0);
}

void		do_lst(t_lst **start, int j)
{
	t_lst	*tmp;
	char	**tab;
	int		max;
	int		ret;

	max = ft_square(j * 4);
	ret = 0;
	tmp = *start;
	while (!ret)
	{
		init_tab(&tab, max);
		ret = find_square(tmp, tab, max);
		free(tab);
		++max;
	}
}
