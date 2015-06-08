/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:32:26 by pxia              #+#    #+#             */
/*   Updated: 2015/01/12 14:13:26 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	char			*tmp;

	i = 0;
	tmp = (char*)s;
	while (i < n)
	{
		if (tmp[i] == (char)c)
			return (tmp + i);
		i++;
	}
	return (NULL);
}
