/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 15:00:55 by pxia              #+#    #+#             */
/*   Updated: 2015/03/25 19:20:22 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void			search_name(t_list *lc, char *buff)
{
	t_list	*tmp;
	int		t;

	tmp = lc;
	t = 0;
	while (tmp != NULL)
	{
		if ((tmp->s_len = ft_search_str(tmp->name, buff)))
			t = 1;
		tmp = tmp->next;
	}
	if (t == 0)
		put_command("bl", 0);
}

static void			move_cursor_search(t_select *sl, char *buff)
{
	t_list *tmp;

	tmp = sl->lc;
	while (tmp != NULL)
	{
		if (!strcmp(tmp->name, buff))
			break ;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return ;
	cursor_dele(sl);
	tmp->indice += 1;
}

static int			name_gestion(t_select *sl, char *name, int *i, char mv)
{
	if (ft_isprint(mv))
	{
		name[*i] = mv;
		name[*i + 1] = '\0';
		(*i)++;
		search_name(sl->lc, name);
	}
	else if (mv == 127 && i > 0)
	{
		(*i)--;
		name[*i] = '\0';
		search_name(sl->lc, name);
	}
	else if (mv == 10)
	{
		move_cursor_search(sl, name);
		return (0);
	}
	return (1);
}

void				search_list(t_select *sl)
{
	char	buff[3];
	char	name[256];
	int		i;

	i = 0;
	bzero(name, 256);
	ft_putstr_fd("S : Search : ", sl->fd_tty);
	while (1)
	{
		bzero(buff, 3);
		read(0, buff, 3);
		put_command("cl", 0);
		if ((name_gestion(sl, name, &i, buff[0])) == 0)
			break ;
		print_list(*sl);
		ft_putstr_fd("S : Search : ", sl->fd_tty);
		ft_putendl_fd(name, sl->fd_tty);
	}
	sl->enable -= SEARCH;
}
