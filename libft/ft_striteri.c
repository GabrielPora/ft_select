/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:24:32 by pxia              #+#    #+#             */
/*   Updated: 2015/01/12 17:23:00 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int l;
	unsigned int i;

	if (!s || !f)
		return ;
	i = 0;
	l = ft_strlen(s);
	while (i < l)
	{
		(*f)(i, &(s[i]));
		i++;
	}
}
