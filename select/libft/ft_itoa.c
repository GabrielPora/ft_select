/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 22:19:02 by pxia              #+#    #+#             */
/*   Updated: 2015/01/12 18:19:46 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int			ft_getnumber(int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int		i;
	int		nb;
	char	*number;

	nb = ft_getnumber(n);
	if ((number = ft_strnew(nb + 1)) == NULL)
		return (NULL);
	if (n == -2147483648)
		return (number = "-2147483648");
	if (n < 0)
		number[0] = '-';
	i = 0;
	while (i < nb)
	{
		if (number[nb - i - 1] == '-')
			break ;
		number[nb - i - 1] = ABS(n) % 10 + 48;
		n = n / 10;
		i++;
	}
	return (number);
}
