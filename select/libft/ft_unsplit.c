/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/08 19:52:59 by pxia              #+#    #+#             */
/*   Updated: 2015/06/08 23:33:31 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			count_char(char **table)
{
	int lengh;
	int i;

	i = 0;
	lengh = ft_tablen(table) - 1;
	while (table[i])
	{
		lengh += ft_strlen(table[i]);
		i++;
	}
	return (lengh);
}

char		*ft_unsplit(char **table)
{
	char	*s;
	int		i;
	int		j;
	int		k;

	k = 0;
	s = ft_strnew(count_char(table) + 1);
	i = 0;
	while (table[i])
	{
		j = 0;
		while (table[i][j])
		{
			s[k] = table[i][j];
			k++;
			j++;
		}
		s[k] = ' ';
		k++;
		i++;
	}
	s[k] = '\0';
	return (s);
}
