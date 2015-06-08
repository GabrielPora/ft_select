/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 14:58:54 by pxia              #+#    #+#             */
/*   Updated: 2015/06/08 23:20:56 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			ft_outc(int c)
{
	write(2, &c, 1);
	return (0);
}

int			put_command(char *command, int aff)
{
	char *res;

	if ((res = tgetstr(command, NULL)) == NULL)
		return (0);
	tputs(res, aff, ft_outc);
	return (1);
}

void		add_end(t_list **list, t_list *element)
{
	t_list *tmp;

	if (*list == NULL)
	{
		*list = element;
		return ;
	}
	tmp = *list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = element;
}

int			get_column(int argc, struct winsize *ws)
{
	int col;

	if (argc == 0)
		return (0);
	ioctl(0, TIOCGWINSZ, ws);
	ws->ws_row -= 3;
	if (ws->ws_row >= argc)
		return (1);
	col = argc / ws->ws_row;
	if (argc % ws->ws_row > 0)
		col++;
	return (col);
}

int			ft_search_str(char *name, char *s)
{
	int len;

	len = ft_strlen(s);
	if (!ft_strncmp(name, s, len))
		return (len);
	return (0);
}
