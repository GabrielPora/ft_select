/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 14:58:38 by pxia              #+#    #+#             */
/*   Updated: 2015/06/08 23:24:07 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static char		*get_name(t_list *lc)
{
	t_list *tmp;

	tmp = lc;
	while (tmp != NULL)
	{
		if (tmp->indice & CURSOR)
			return (tmp->name);
		tmp = tmp->next;
	}
	return (NULL);
}

void	put_help(int fd_tty)
{
	put_command("cl", 0);
	ft_color(WHITE_BLUE, "Unknown file\n", RESET, fd_tty);
	ft_color(BLUE, "Directory\n", RESET, fd_tty);
	ft_color(MAGENTA, "Symbolic link\n", RESET, fd_tty);
	ft_color(BRUN, "Pipe\n", RESET, fd_tty);
	ft_color(GREEN, "Socket\n", RESET, fd_tty);
	ft_color(BLUE_CYAN, "Block file\n", RESET, fd_tty);
	ft_color(BLUE_YELLOW, "Special file\n", RESET, fd_tty);
	ft_color(RED, "Executable file\n", RESET, fd_tty);
	ft_color(WHITE, "Regular file\n", RESET, fd_tty);
	ft_putstr_fd("\n\n Select commands \n", fd_tty);
	ft_putstr_fd
	(" A : Select all \n S : Search \n I : Get file info (if a file)\n",
	fd_tty);
	ft_putstr_fd(" H : Help \n ", fd_tty);
}

static void		put_info(struct stat buff, char *filename, t_select *sl)
{
	char *tmp;
	char *mode;

	mode = get_filemode(buff.st_mode);
	tmp = ft_itoa(buff.st_size);
	ft_putstr_fd("filename  :", sl->fd_tty);
	ft_color(BOLD, filename, RESET, sl->fd_tty);
	ft_putstr_fd("\n", sl->fd_tty);
	ft_putstr_fd("filesize  :", sl->fd_tty);
	ft_color(BOLD, tmp, RESET, sl->fd_tty);
	ft_putstr_fd("\n", sl->fd_tty);
	ft_putstr_fd("filemode  :", sl->fd_tty);
	ft_color(BOLD, mode, RESET, sl->fd_tty);
	ft_putstr_fd("\n", sl->fd_tty);
	free(tmp);
	free(mode);
}

void			get_info(t_select *sl)
{
	struct stat		buff;
	char			*filename;

	filename = get_name(sl->lc);
	put_command("cl", 0);
	if ((lstat(filename, &buff)) != -1)
		put_info(buff, filename, sl);
	else
		ft_putstr_fd("Not a existant file.\n", sl->fd_tty);
}
