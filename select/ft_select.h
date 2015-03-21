#ifndef FT_SELECT_H
# define FT_SELECT_H
# define SELECTED 0b00000010
# define CURSOR 0b00000001
# define RESTART 0b00000001

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <curses.h>
#include <term.h>
#include <string.h>
#include <sys/ioctl.h>

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
  struct s_list *next;
}		t_list;

typedef struct s_select
{
  t_list *lc;
  int argc;
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

void select_arg(t_select *sl);
void sig_winch(int signo);
int ft_outc(int c);
t_select init_list(int argc, char **argv);
int put_command(char *command, int aff);
void add_end(t_list **list, t_list *element);
int get_column(int argc, struct winsize *ws);
void check_window_size(t_select sl);
void print_list(t_select sl);
void direction_key(t_select *sl, int c);
void sig_cont(int signo);
void sig_stop(int signo);
int term_set(struct termios *term);

#endif
