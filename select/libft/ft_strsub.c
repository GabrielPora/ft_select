/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:51:11 by pxia              #+#    #+#             */
/*   Updated: 2015/01/12 19:52:46 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strsub(const char *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	l;
	unsigned int	i;

	if (!s)
		return (NULL);
	if ((str = ft_strnew(len + 1)) == NULL)
		return (str);
	l = ft_strlen(s);
	if (start + len <= l)
	{
		i = 0;
		while (i < len)
		{
			str[i] = s[start + i];
			i++;
		}
		str[i] = '\0';
	}
	else
		return (NULL);
	return (str);
}
