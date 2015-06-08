/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prin.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 15:01:39 by pxia              #+#    #+#             */
/*   Updated: 2015/03/25 18:46:00 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void print_name(t_list *lc, int fd_tty)
{
	if (lc->indice & CURSOR)
		ft_putstr_fd("\033[1m", fd_tty);
	if (lc->indice & SELECTED)
		ft_putstr_fd("\033[7m", fd_tty);
	ft_putstr_fd(lc->color, fd_tty);
	ft_putstr_fd(lc->name, fd_tty);
	ft_putstr_fd("\033[0m", fd_tty);
}

void print_search(t_list *lc, int fd_tty)
{
	write(fd_tty, INVERSE, strlen(INVERSE));
	write(fd_tty, lc->name, lc->s_len);
	write(fd_tty, RESET, strlen(RESET));
	write(fd_tty, lc->name + lc->s_len, lc->len - lc->s_len);
}

void print_col(int fd_tty)
{
	ft_putstr_fd(BOLD, fd_tty);
	ft_putstr_fd(" | ", fd_tty);
	ft_putstr_fd(RESET, fd_tty);
}

void print_list(t_select sl)
{
	int k;

	put_command("cl", 0);
	while (sl.lc != NULL)
	{
		if (sl.enable & SEARCH)
			print_search(sl.lc, sl.fd_tty);
		else
			print_name(sl.lc, sl.fd_tty);
		k = 0;
		if (sl.lc->next && (sl.lc->next->row == sl.lc->row))
		{
			while (k < sl.sp[sl.lc->col] - sl.lc->len)
			{
				ft_putstr_fd(" ", sl.fd_tty);
				k++;
			}
			print_col(sl.fd_tty);
		}
		else
			ft_putstr_fd("\n", sl.fd_tty);
		sl.lc = sl.lc->next;
	}
}
