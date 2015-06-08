/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:33:25 by pxia              #+#    #+#             */
/*   Updated: 2014/11/10 17:08:06 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int i;

	if (!dest || !src || n <= 0)
		return (dest);
	i = 0;
	while (i < n)
	{
		if ((char*)dest > (char*)src)
			((char*)dest)[n - i - 1] = ((char*)src)[n - i - 1];
		else
			((char*)dest)[i] = ((char*)src)[i];
		i++;
	}
	return (dest);
}
