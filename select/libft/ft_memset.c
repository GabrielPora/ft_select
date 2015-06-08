/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:33:43 by pxia              #+#    #+#             */
/*   Updated: 2014/11/10 17:23:34 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memset(void *s, int c, size_t n)
{
	char *tmp;

	if (!s)
		return (NULL);
	tmp = s;
	while (n-- > 0)
	{
		tmp[n] = (unsigned char)c;
	}
	return ((char*)s);
}
