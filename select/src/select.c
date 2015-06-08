/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 16:04:38 by pxia              #+#    #+#             */
/*   Updated: 2015/06/08 23:10:56 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void select_all(t_select *sl)
{
	t_list *tmp;

	tmp = sl->lc;
	while (tmp != NULL)
	{
		if ((tmp->indice & SELECTED) == 0)
			tmp->indice += SELECTED;
		tmp = tmp->next;
	}
}

void unselect_all(t_select *sl)
{
	t_list *tmp;

	tmp = sl->lc;
	while (tmp != NULL)
	{
		if (tmp->indice & SELECTED)
			tmp->indice -= SELECTED;
		tmp = tmp->next;
	}
}

void send_selected(t_list *lc)
{
	t_list *tmp;

	tmp = lc;
	while (tmp != NULL)
	{
		if (tmp->indice & SELECTED)
			ft_color(tmp->name, " ", "", 1);
		tmp = tmp->next;
	}
}

void delete_select(t_select *sl)
{
	t_list *tmp;

	tmp = sl->lc;
	while (tmp != NULL)
	{
		if (tmp->indice & CURSOR && tmp->indice & SELECTED)
			tmp->indice -= SELECTED;
		tmp = tmp->next;
	}
	print_list(*sl);
}

void select_arg(t_select *sl)
{
	t_list *tmp;

	tmp = sl->lc;
	while (tmp != NULL)
	{
		if (tmp->indice & CURSOR)
			break ;
		tmp = tmp->next;
	}
	if (tmp->indice & SELECTED)
		tmp->indice -= 3;
	else
		tmp->indice += 1;
	go_to_next(sl, tmp);
	print_list(*sl);
}
