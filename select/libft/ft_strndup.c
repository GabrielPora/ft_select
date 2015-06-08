/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 17:09:58 by pxia              #+#    #+#             */
/*   Updated: 2015/02/26 19:01:29 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strndup(char *str, size_t n)
{
	char*tmp;

	if ((tmp = ft_strnew(n)))
		return (tmp);
	ft_strncpy(tmp, str, n);
	return (tmp);
}
