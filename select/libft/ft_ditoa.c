/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ditoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 11:40:28 by pxia              #+#    #+#             */
/*   Updated: 2015/01/23 20:31:11 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_d_getnumber(double n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n > 1 || n < -1)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_ditoa(double n, int c)
{
	int		nb;
	double	ent;
	char	*s;
	int		i;

	if ((nb = ft_d_getnumber(n)) >= c)
		return (ft_itoa((nb = n)));
	s = ft_strnew(c + 2);
	s[nb] = '.';
	ent = (n * ft_exp(10, c - nb));
	i = 0;
	while (i < c + 1)
	{
		if (s[c - i] == '.')
		{
			i++;
			continue ;
		}
		s[c - i] = fmod(ent, 10) + 48;
		ent = ent / 10;
		i++;
	}
	return (s);
}
