/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:38:16 by pxia              #+#    #+#             */
/*   Updated: 2015/01/12 13:45:23 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcat(char *dest, const char *src, size_t n)
{
	unsigned int d;
	unsigned int s;
	unsigned int i;

	d = ft_strlen(dest);
	s = ft_strlen(src);
	if (n == 0)
		return (s);
	if (d + 1 >= n)
		return (s + n);
	i = 0;
	while (d + i + 1 < n && src[i])
	{
		dest[d + i] = src[i];
		i++;
	}
	if (d + i + 1 < n)
		dest[d + i] = '\0';
	return (d + s);
}
