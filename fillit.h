/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 00:12:09 by jgan              #+#    #+#             */
/*   Updated: 2015/12/17 17:54:25 by jfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"

typedef struct		s_xy
{
	int				x;
	int				y;
}					t_xy;
typedef struct		s_lst
{
	char			nb;
	t_xy			*form;
	struct s_lst	*next;
}					t_lst;
int					check_file(char *file);
int					build_lst(char *file, t_lst **start, int j);
int					add_lst(t_lst **start, char **tab);
void				do_lst(t_lst **start, int j);
int					ft_square(int j);
#endif
