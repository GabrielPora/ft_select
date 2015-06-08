/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_ascii.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/06 13:54:28 by pxia              #+#    #+#             */
/*   Updated: 2015/06/08 23:32:58 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countbloc(const char *s, int (*f)(int c))
{
	int		nb;
	int		i;

	nb = 0;
	i = 0;
	while (s[i])
	{
		while (!(*f)(s[i]))
			i++;
		if (s[i] == '\0')
			break ;
		nb++;
		while ((*f)(s[i]) && s[i] != '\0')
			i++;
	}
	return (nb);
}

static char		**get_null_tab(void)
{
	char **tab;

	tab = (char**)malloc(sizeof(char*));
	*tab = ft_strnew(1);
	return (tab);
}

static char		**get_tab(const char *s, int (*f)(int c))
{
	char	**tab;
	int		nb;
	int		i;
	int		o;

	nb = ft_countbloc(s, (*f));
	i = 0;
	tab = (char**)malloc(sizeof(char*) * (nb + 1));
	nb = 0;
	while (s[i] != '\0')
	{
		while (!(*f)(s[i]) && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			break ;
		o = i;
		while ((*f)(s[i]) && s[i] != '\0')
			i++;
		tab[nb] = ft_strnew(i - o + 1);
		ft_strncpy(tab[nb], s + o, i - o);
		nb++;
	}
	tab[nb] = NULL;
	return (tab);
}

char			**ft_strsplit_ascii(const char *s, int type)
{
	if (!s)
		return (get_null_tab());
	else
	{
		if (type == 0)
			return (get_tab(s, ft_isdigit));
	}
	return (get_tab(s, ft_isalpha));
}
