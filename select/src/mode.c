/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 14:16:28 by pxia              #+#    #+#             */
/*   Updated: 2015/06/08 23:17:22 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

char *get_filemode(mode_t mode)
{
	char *s;

	s = (char*)malloc(sizeof(char) * 10);
	s[0] = (mode & S_IRUSR) ? 'r' : '-';
	s[1] = (mode & S_IWUSR) ? 'w' : '-';
	if ((mode & S_ISUID))
		s[2] = 's';
	else
		s[2] = (mode & S_IXUSR) ? 'x' : '-';
	s[3] = (mode & S_IRGRP) ? 'r' : '-';
	s[4] = (mode & S_IWGRP) ? 'w' : '-';
	if ((mode & S_ISGID))
		s[5] = 's';
	else
		s[5] = (mode & S_IXGRP) ? 'x' : '-';
	s[6] = (mode & S_IROTH) ? 'r' : '-';
	s[7] = (mode & S_IWOTH) ? 'w' : '-';
	if ((mode & S_IXOTH))
		s[8] = (S_ISVTX & mode) ? 't' : 'x';
	else
		s[8] = (S_ISVTX & mode) ? 'T' : '-';
	s[9] = '\0';
	return (s);
}
