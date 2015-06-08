/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colorstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 17:41:09 by pxia              #+#    #+#             */
/*   Updated: 2015/05/05 17:58:28 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_colorstring(char *color, char *msg)
{
	ft_putstr(color);
	ft_putstr(msg);
	ft_putstr(C_RESET);
}
