/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 17:18:43 by pxia              #+#    #+#             */
/*   Updated: 2015/05/05 17:49:24 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin_free(char **s1, char *s2, int n)
{
	char *s;

	if (s1[0] == '\0')
		return (ft_strndup(s2, n));
	else
	{
		s = ft_strnew(ft_strlen(*s1) + 1 + n);
		ft_strcpy(s, *s1);
		ft_strncat(s, s2, n);
		free(*s1);
	}
	return (s);
}

int		readline(int fd, char **rest, char **line)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;
	int		i;

	ft_bzero(buff, BUFF_SIZE);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		i = 0;
		while (buff[i] && buff[i] != '\n')
			i++;
		if (buff[i] == '\n')
		{
			*line = ft_strnjoin_free(line, buff, i);
			*rest = ft_strdup(buff + i + 1);
			break ;
		}
		else
		{
			*line = ft_strnjoin_free(line, buff, i);
		}
	}
	if (ret == -1)
		return (ret);
	return (ret);
}

int		return_rest(int fd, char **rest, char **line, int *avt)
{
	int tmp;

	tmp = *avt;
	while ((*rest)[*avt] && (*rest)[*avt] != '\n')
		(*avt)++;
	*line = ft_strnjoin_free(line, (*rest) + tmp, *avt - tmp);
	if ((*rest)[*avt] == '\0' || (*rest)[*avt + 1] == '\0')
	{
		*avt = 0;
		free((*rest));
		(*rest) = NULL;
		return (readline(fd, rest, line));
	}
	(*avt)++;
	return (1);
}

void	reset(char **rest, int *avt)
{
	free(*rest);
	*rest = NULL;
	*avt = 0;
}

int		get_next_line(int const fd, char **line)
{
	static int	o_fd;
	static char *rest;
	static int	avt;

	*line = ft_strnew(1);
	if (fd != o_fd)
		reset(&rest, &avt);
	o_fd = fd;
	if (!rest)
	{
		avt = 0;
		return (readline(fd, &rest, line));
	}
	else if (rest[avt] == '\n')
	{
		avt++;
		return (1);
	}
	else
		return (return_rest(fd, &rest, line, &avt));
}
