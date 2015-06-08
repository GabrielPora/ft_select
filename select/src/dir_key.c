/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 14:58:32 by pxia              #+#    #+#             */
/*   Updated: 2015/06/08 23:17:14 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_pos		cursor_dele(t_select *sl)
{
	t_pos	pos;
	t_list	*tmp;

	tmp = sl->lc;
	while (tmp != NULL)
	{
		if (tmp->indice & CURSOR)
			break ;
		tmp = tmp->next;
	}
	tmp->indice -= 1;
	pos.row = tmp->row;
	pos.col = tmp->col;
	return (pos);
}

void		cursor_add(t_select *sl, t_pos pos)
{
	t_list *tmp;

	tmp = sl->lc;
	while (tmp->next != NULL)
	{
		if (tmp->row == pos.row && tmp->col == pos.col)
			break ;
		tmp = tmp->next;
	}
	tmp->indice += 1;
}

void		pos_gestion(t_pos *pos, int max_row, int max_col, t_select *sl)
{
	if (pos->col == max_col || (pos->row > sl->l_row && pos->col == sl->l_col))
		pos->col = 0;
	else if (pos->col == -1)
		pos->col = pos->row > sl->l_row ? max_col - 2 : max_col - 1;
	if (pos->row == max_row || (pos->col == sl->l_col && pos->row > sl->l_row))
	{
		pos->row = 0;
		if (pos->col == sl->l_col)
			pos->col = 0;
		else
			pos->col += 1;
	}
	else if (pos->row == -1 && pos->col == 0)
	{
		pos->col = sl->l_col;
		pos->row = sl->l_row;
	}
	else if (pos->row == -1 && pos->col > 0)
	{
		pos->row = max_row - 1;
		pos->col -= 1;
	}
}

void		go_to_next(t_select *sl, t_list *el)
{
	t_pos pos;

	pos.row = el->row + 1;
	pos.col = el->col;
	pos_gestion(&pos, sl->max_row, sl->max_col, sl);
	cursor_add(sl, pos);
}

void		direction_key(t_select *sl, int c)
{
	t_pos pos;

	pos = cursor_dele(sl);
	if (c == 65)
		pos.row--;
	else if (c == 66)
		pos.row++;
	else if (c == 67)
		pos.col++;
	else if (c == 68)
		pos.col--;
	pos_gestion(&pos, sl->max_row, sl->max_col, sl);
	cursor_add(sl, pos);
	print_list(*sl);
}
