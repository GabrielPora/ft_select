/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 23:31:05 by pxia              #+#    #+#             */
/*   Updated: 2015/05/08 16:48:45 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_join_all(int number, ...)
{
	va_list ap;
	char	*s1;
	char	*s2;
	char	*s;

	if (number < 2)
		return (NULL);
	va_start(ap, number);
	s1 = va_arg(ap, char *);
	s2 = va_arg(ap, char *);
	if ((s = ft_strjoin(s1, s2)) == NULL)
		return (NULL);
	number -= 2;
	while (number > 0)
	{
		s1 = va_arg(ap, char *);
		s2 = s;
		if ((s = ft_strjoin(s, s1)) == NULL)
			return (NULL);
		free(s2);
		number--;
	}
	return (s);
}
