/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:33:54 by pxia              #+#    #+#             */
/*   Updated: 2015/01/12 17:31:12 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	l;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	l = ft_strlen(s);
	i = 0;
	str = ft_strnew(l + 1);
	while (i < l)
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	return (str);
}
