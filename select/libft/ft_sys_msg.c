/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sys_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 11:58:18 by pxia              #+#    #+#             */
/*   Updated: 2015/05/23 17:48:20 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_sys_msg(char *prevent, char *type, char *type_color, char *msg)
{
	ft_colorstring(C_GREEN, prevent);
	ft_colorstring(type_color, type);
	ft_colorstring(C_BOLD, msg);
	ft_putchar('\n');
	if (!ft_strcmp(type_color, C_RED))
		return (0);
	return (1);
}
