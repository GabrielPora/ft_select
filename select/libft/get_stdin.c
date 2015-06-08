/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stdin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 19:42:00 by pxia              #+#    #+#             */
/*   Updated: 2015/05/05 17:49:52 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_join(char **rest, char *buff, int len)
{
	char *ptr;

	ptr = *rest;
	*rest = ft_strnjoin(*rest, buff, len);
	free(ptr);
}

int		get_stdin(int const fd, char **line)
{
	int		ret;
	char	*buff;
	int		i;

	buff = ft_strnew(BUFF_SIZE + 1);
	*line = ft_strnew(1);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		i = 0;
		buff[ret] = '\0';
		while (buff[i] && buff[i] != '\n')
			i++;
		if (buff[i] == '\n')
		{
			free_join(line, buff, i);
			free(buff);
			return (ft_strlen(*line));
		}
		else
			free_join(line, buff, BUFF_SIZE);
	}
	free(buff);
	return (ft_strlen(*line));
}
