/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 20:25:40 by pxia              #+#    #+#             */
/*   Updated: 2015/01/12 20:11:24 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char *ft_strtrim(const char *s)
{
	char	*str;
	int		i;
	int		l;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	if (s[i] == '\0')
		return ((str = ft_strnew(1)));
	s += i;
	l = ft_strlen(s);
	while (s[l - 1] && (s[l - 1] == ' '
						|| s[l - 1] == '\t' || s[l - 1] == '\n'))
		l--;
	if ((str = ft_strnew(l + 1)) == 0)
		return (0);
	i = 0;
	while (i < l)
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}
