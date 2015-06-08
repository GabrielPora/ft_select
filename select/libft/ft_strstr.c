/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:40:54 by pxia              #+#    #+#             */
/*   Updated: 2015/01/12 13:52:00 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strstr(const char *s1, const char *s2)
{
	unsigned int i;
	unsigned int k;
	unsigned int len;

	if (*s2 == '\0')
		return ((char*)(s1));
	i = 0;
	len = ft_strlen(s2);
	while (s1[i])
	{
		k = 0;
		while (s2[k] == s1[i + k] && i + k < ft_strlen(s1))
			k++;
		if (k == len)
			return ((char*)(s1 + i));
		i++;
	}
	return (NULL);
}
