/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:28:07 by pxia              #+#    #+#             */
/*   Updated: 2015/06/08 23:35:00 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define ABS(x) ((x) < 0 ? - (x) : (x))
# define BUFF_SIZE	1
# define ERROR 0
# define SUCCESS 1
# define C_CLEAR ("\033[H\033[2J")
# define C_RESET ("\033[0m")
# define C_BOLD ("\033[1m")
# define C_REV ("\033[7m")
# define C_RESET ("\033[0m")
# define C_WHITE ("\x1B[0m")
# define C_RED ("\x1B[31m")
# define C_GREEN ("\x1B[32m")
# define C_YELLOW ("\x1B[33m")
# define C_BLUE ("\x1B[34m")
# define C_MAGENTA ("\x1B[35m")
# define SYS "[SERVER]"

# define C_BWHITE ("\033[1m\x1B[0m")
# define C_BRED ("\033[1m\x1B[31m")
# define C_BGREEN ("\033[1m\x1B[32m")
# define C_BYELLOW ("\033[1m\x1B[33m")
# define C_BBLUE ("\033[1m\x1B[34m")
# define C_BMAGENTA ("\033[1m\x1B[35m")
# define C_BCYAN ("\033[1m\x1B[36m")
# define C_BGRAY ("\033[1m\033[22;37m")

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <math.h>
# include <stdarg.h>

int					ft_isnum(char *s);
void				ft_freetab(char **table);
char				*ft_unsplit(char **table);
char				*ft_whitespace(char *str);
char				*ft_join_all(int number, ...);
int					ft_tablen(char **table);
void				ft_tabcpy(char ***dest, char **src);
char				*ft_getpath(char *dirname, char *filename);
int					ft_exp(int n, int p);
int					get_next_line(int const fd, char **line);
int					get_stdin(int const fd, char **line);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strnjoin(const char *s1, const char *s2, int n);
char				*ft_strndup(char *str, size_t n);
void				ft_reverse_str(char *str);
void				ft_puttab(char **table);
int					ft_intchr(char *str, char c);
char				*ft_get_line(int fd);
int					ft_nbrlen(int nb);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char*src, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strstr(const char *s1, const char*s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_atoi(const char *s1);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_stralnum(char *str);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strtrim(const char *s);
char				**ft_strsplit(const char *s, char c1, char c2);
char				**ft_strsplit_ascii(const char *s, int type);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(const char *s);
void				ft_putendl(const char *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_ditoa(double n, int c);
int					ft_sys(char *msg, int error_value, int value, int end);
int					ft_sys_msg(char *prevent, char *type,
char *color, char *msg);
void				ft_colorstring(char *color, char *msg);
void				ft_color(char *s1, char *s2, char *s3, int fd);
char				*ft_addnum(char *s, int num);
char				*ft_str_trans(char *s);

#endif
