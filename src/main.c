/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 14:59:01 by pxia              #+#    #+#             */
/*   Updated: 2015/06/08 22:06:27 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			term_set(t_term *term)
{
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_lflag |= ISIG;
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, term))
		return (0);
	return (1);
}

int			exit_select(t_term *term)
{
	tcgetattr(0, term);
	term->c_lflag |= ICANON;
	term->c_lflag |= ECHO;
	tcsetattr(0, 0, term);
	return (0);
}

static int	key_gestion(t_select *sl, char *buffer)
{
	if (buffer[0] == 4)
		return (0);
	if (buffer[0] == 27 && sl->enable & WIN_OK)
		direction_key(sl, buffer[2]);
	else if (buffer[0] == 32 && sl->enable & WIN_OK)
		select_arg(sl);
	else if (buffer[0] == 104 && sl->enable & WIN_OK)
		put_help(sl->fd_tty);
	else if (buffer[0] == 105 && sl->enable & WIN_OK)
		get_info(sl);
	else if (buffer[0] == 127 && sl->enable & WIN_OK)
		delete_select(sl);
	else if (buffer[0] == 115 && sl->enable & WIN_OK)
	{
		sl->enable += SEARCH;
		search_list(sl);
		print_list(*sl);
	}
	else if (buffer[0] == 10)
		return (1);
	return (2);
}

static int	voir_touche(t_select *sl)
{
	char		buffer[3];
	int			i;

	print_list(*sl);
	while (1)
	{
		bzero(buffer, 3);
		read(0, buffer, 3);
		i = key_gestion(sl, buffer);
		if (i == 1)
			break ;
		else if (i == 0)
		{
			close(sl->fd_tty);
			return (0);
		}
	}
	close(sl->fd_tty);
	send_selected(sl->lc);
	return (0);
}

int			main(int argc, char **argv)
{
	t_select		sl;
	t_term			term;
	char			*name;

	if ((name = getenv("TERM")) == NULL)
		return (0);
	if (tgetent(NULL, name) == ERR)
		return (0);
	if (tcgetattr(0, &term) == -1)
		return (0);
	if (!term_set(&term))
		return (0);
	term_set(&term);
	signal_handler();
	sl = init_list(argc - 1, argv + 1);
	sl.term = term;
	if (sl.lc == NULL)
		return (exit_select(&term));
	g_select_tmp = &sl;
	sl.lc->indice = 1;
	voir_touche(&sl);
	return (0);
}
