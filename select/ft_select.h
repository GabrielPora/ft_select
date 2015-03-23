#ifndef FT_SELECT_H
# define FT_SELECT_H
# define SELECTED 0b00000010
# define CURSOR 0b00000001
# define RESTART 0b00000001
# define SEARCH 0b00000010
# define WIN_OK 0b00000001

# define WHITE "\033[37m"
# define CYAN "\033[36m"
# define MAGENTA "\033[35m"
# define BLUE "\033[34m"
# define BRUN "\033[33m"
# define GREEN "\033[32m"
# define RED "\033[31m"
# define BLACK "\033[30m"
# define HIDE "\033[8m"
# define INVERSE "\033[7m"
# define UNDERLINE "\033[4m"
# define BOLD "\033[1m"
# define RESET "\033[0m"
# define BLUE_CYAN "\033[34;46m"
# define BLUE_YELLOW "\033[34;43m"
# define WHITE_BLUE "\033[37;44m"

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <curses.h>
#include <term.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <ctype.h>

typedef struct s_pos
{
  int row;
  int col;
}		t_pos;

typedef struct s_list
{
  char *name;
  int col;
  int row;
  int len;
  int indice;
  int s_len;
  char *color;
  struct s_list *next;
}		t_list;

typedef struct s_select
{
  t_list *lc;
  t_list **lt;
  int argc;
  int enable;
  int max_row;
  int max_col;
  int l_row;
  int l_col;
  int col_len;
  int *sp;
  int fd_tty;
  struct termios term;
}		t_select;

t_select *select_tmp;

void put_help(void);
void put_info(t_select *sl);
t_pos cursor_dele(t_select *sl);
void window_resize(t_select *sl);
void last_col(t_select sl, int *row, int *col);
void get_sp(t_select *sl);
t_list *get_list(int argc, t_list **lt, int max_row, int max_col);
void select_arg(t_select *sl);
void sig_winch(int signo);
int ft_outc(int c);
t_select init_list(int argc, char **argv);
int put_command(char *command, int aff);
void add_end(t_list **list, t_list *element);
int get_column(int argc, struct winsize *ws);
int check_window_size(t_select sl);
void print_list(t_select sl);
void direction_key(t_select *sl, int c);
void sig_cont(int signo);
void sig_stop(int signo);
int term_set(struct termios *term);
void search_list(t_select *sl);
int ft_search_str(char *name, char *s);
void select_all(t_select *sl);
void unselect_all(t_select *sl);
void signal_handler(void);

#endif
