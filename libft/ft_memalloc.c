/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:57:09 by pxia              #+#    #+#             */
/*   Updated: 2014/11/05 19:06:44 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memalloc(size_t size)
{
	void *s;

	if (size == 0)
		return (0);
	s = (void*)malloc(sizeof(void) * size);
	if (s == NULL)
		return (0);
	ft_bzero(s, size);
	return (s);
}
