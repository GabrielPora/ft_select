#ifndef FT_SELECT_H
# define FT_SELECT_H
# define SELECTED 0b00000010
# define CURSOR 0b00000001

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
  int x;
  int y;
}		t_pos;

typedef struct s_list
{
  char *name;
  int len;
  int indice;
  struct s_list *next;
}		t_list;

typedef struct s_select
{
  t_list **lc;
  int argc;
  int max_row;
  int max_col;
  int col_len;
  int *sp;
}		t_select;

t_select *tmp;

void sig_winch(int signo);
int ft_outc(int c);
int put_command(char *command, int aff);
void add_end(t_list **list, t_list *element);
int get_column(int argc, struct winsize *ws);
void check_window_size(t_select sl);
void print_list(t_select sl);

#endif
