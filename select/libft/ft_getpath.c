/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 14:18:44 by pxia              #+#    #+#             */
/*   Updated: 2015/01/19 14:21:45 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_getpath(char *dirname, char *filename)
{
	char *path;
	char *ptr;

	path = ft_strjoin(dirname, "/");
	ptr = path;
	path = ft_strjoin(path, filename);
	free(ptr);
	return (path);
}
