/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 14:58:45 by pxia              #+#    #+#             */
/*   Updated: 2015/06/08 23:18:56 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void sig_cont(int signo)
{
	if (signo == SIGCONT)
	{
		term_set(&(g_select_tmp->term));
		window_resize(g_select_tmp);
	}
}

void sig_winch(int signo)
{
	if (signo == SIGWINCH)
		window_resize(g_select_tmp);
}

void sig_tstp(int signo)
{
	char cp[2];

	cp[0] = g_select_tmp->term.c_cc[VSUSP];
	cp[1] = 0;
	if (signo == SIGTSTP)
	{
		exit_select(&(g_select_tmp->term));
		signal(SIGTSTP, SIG_DFL);
		ioctl(0, TIOCSTI, cp);
	}
}

void sig_int(int signo)
{
	if (signo == SIGINT)
	{
		exit_select(&(g_select_tmp->term));
		exit(0);
	}
}

void signal_handler(void)
{
	signal(SIGWINCH, sig_winch);
	signal(SIGINT, sig_int);
	signal(SIGCONT, sig_cont);
	signal(SIGTSTP, sig_tstp);
}
