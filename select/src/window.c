/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 15:02:12 by pxia              #+#    #+#             */
/*   Updated: 2015/06/08 23:22:14 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_list		*get_list(int argc, t_list **lt, int max_row, int max_col)
{
	int			i;
	t_list		*list;
	t_list		*tmp;
	int			col;
	int			row;

	i = 0;
	row = 0;
	list = NULL;
	while (row < max_row)
	{
		col = 0;
		while (col < max_col && (i = row + max_row * col) < argc)
		{
			tmp = lt[i];
			tmp->row = row;
			tmp->col = col;
			tmp->next = NULL;
			add_end(&list, tmp);
			col++;
		}
		row++;
	}
	return (list);
}

int			check_window_size(t_select sl)
{
	int i;
	int line_len;

	i = 0;
	line_len = 0;
	while (i < sl.max_col)
	{
		line_len += sl.sp[i] + 3;
		i++;
	}
	if (line_len > sl.col_len)
	{
		put_command("cl", 0);
		printf("window size too small.\n");
		return (0);
	}
	print_list(sl);
	return (1);
}

void		window_resize(t_select *sl)
{
	struct winsize ws;

	sl->max_col = get_column(sl->argc, &ws);
	sl->max_row = ws.ws_row;
	sl->col_len = ws.ws_col;
	sl->lc = get_list(sl->argc, sl->lt, sl->max_row, sl->max_col);
	free(sl->sp);
	sl->sp = (int*)malloc(sizeof(int) * sl->max_col + 1);
	get_sp(sl);
	last_col(*sl, &(sl->l_row), &(sl->l_col));
	sl->enable = check_window_size(*sl);
}
