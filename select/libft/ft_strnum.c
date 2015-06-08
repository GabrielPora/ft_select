/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 11:59:03 by pxia              #+#    #+#             */
/*   Updated: 2015/05/27 12:02:16 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_stralnum(char *str)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) && ret != 1)
		{
			if (ret != 0)
				return (0);
			ret = 1;
		}
		if (ft_isalpha(str[i]) && ret != 2)
		{
			if (ret != 0)
				return (0);
			ret = 2;
		}
		i++;
	}
	return (ret);
}
