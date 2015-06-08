/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:33:00 by pxia              #+#    #+#             */
/*   Updated: 2015/01/12 20:14:05 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int i;

	i = 0;
	if (!dest || !src || n == 0)
		return (dest);
	while (i < n)
	{
		((char*)dest)[i] = ((char*)src)[i];
		i++;
	}
	while (i < n)
	{
		((char*)dest)[i] = '\0';
		i++;
	}
	return (dest);
}
