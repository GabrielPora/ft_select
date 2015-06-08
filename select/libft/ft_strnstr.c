/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:40:04 by pxia              #+#    #+#             */
/*   Updated: 2014/11/08 22:11:57 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int i;
	unsigned int j;
	unsigned int len;

	i = 0;
	len = ft_strlen(s2);
	while (i < n && i < ft_strlen(s1))
	{
		j = 0;
		while (s1[i + j] == s2[j] && s1[i + j] != '\0' && i + j < n)
			j++;
		if (j == len)
			return ((char*)(s1 + i));
		i++;
	}
	return (NULL);
}
