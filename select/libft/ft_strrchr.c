/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:40:36 by pxia              #+#    #+#             */
/*   Updated: 2014/11/09 16:36:49 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	int i;
	int n;

	i = 0;
	n = ft_strlen(s);
	while (i <= n)
	{
		if (s[n - i] == (unsigned char)c)
			return ((char*)(s + n - i));
		i++;
	}
	return (NULL);
}
