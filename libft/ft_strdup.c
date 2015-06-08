/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:35:18 by pxia              #+#    #+#             */
/*   Updated: 2015/01/12 19:22:19 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strdup(const char *s)
{
	char	*tmp;

	if ((tmp = ft_strnew(ft_strlen(s) + 1)) == NULL)
		return (tmp);
	ft_strcpy(tmp, s);
	return (tmp);
}
