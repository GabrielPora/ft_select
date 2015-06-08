/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 12:41:10 by pxia              #+#    #+#             */
/*   Updated: 2015/05/08 16:34:51 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_addnum(char *s, int num)
{
	char *tmp;
	char *str;

	if ((tmp = ft_itoa(num)) == NULL)
		return (NULL);
	if ((str = ft_strjoin(s, tmp)) == NULL)
		return (NULL);
	free(tmp);
	return (str);
}
