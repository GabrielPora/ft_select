/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sys.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 17:34:37 by pxia              #+#    #+#             */
/*   Updated: 2015/05/06 12:36:14 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check(char *msg, int id)
{
	if (id == ERROR)
	{
		ft_colorstring(C_RED, " Error : ");
		ft_colorstring(C_BOLD, msg);
		ft_putchar('\n');
		exit(0);
	}
	else
	{
		ft_colorstring(C_YELLOW, " Success : ");
		ft_colorstring(C_BOLD, msg);
		ft_putchar('\n');
	}
	return (1);
}

int		ft_sys(char *msg, int start, int end, int value)
{
	int id;

	id = 1;
	ft_colorstring(C_GREEN, SYS);
	if (start == end)
	{
		if (value != start)
			id = 0;
	}
	else if (start == -10)
	{
		if (value >= end)
			id = 0;
	}
	else if (end == -10)
	{
		if (value <= start)
			id = 0;
	}
	else
	{
		if (value < start || value > end)
			id = 0;
	}
	return (ft_check(msg, id));
}
