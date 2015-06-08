/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:40:10 by pxia              #+#    #+#             */
/*   Updated: 2015/01/12 17:31:59 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strnequ(const char *s1, const char *s2, size_t n)
{
	unsigned int i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	if (n == 0)
		return (1);
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (1);
		i++;
		if (i == n)
			return (1);
	}
	return (0);
}
