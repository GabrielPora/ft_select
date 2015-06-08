/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:18:23 by pxia              #+#    #+#             */
/*   Updated: 2015/02/26 19:01:21 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnew(size_t size)
{
	char *s;

	s = (char*)malloc(sizeof(char) * size + 1);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, size);
	return (s);
}
