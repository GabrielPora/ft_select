#include "ft_select.h"

t_list *get_list(int argc, char **argv, int max_row, int max_col)
{
  int i;
  t_list *list;
  t_list *tmp;
  int col;
  int row;

  i = 0;
  row = 0;
  list = NULL;
  while (row < max_row)
    {
      col = 0;
      while (col < max_col && (i = row + max_row * col) < argc)
	{
	  tmp = (t_list*)malloc(sizeof(t_list));
	  tmp->name = argv[i];
	  tmp->len = strlen(tmp->name);
	  tmp->indice = 0;
	  tmp->row = row;
	  tmp->col = col;
	  tmp->next = NULL;
	  add_end(&list, tmp);
	  col++;
	}
      row++;
    }
  return (list);
}

void get_sp(t_select *sl)
{
  t_list *tmp;
  int sp;
  int col;

  col = 0;
  while (col < sl->max_col)
    {
      sp = 0;
      tmp = sl->lc;
      while (tmp != NULL)
	{
	  if (tmp->col == col)
	    sp = tmp->len > sp ? tmp->len : sp;
	  tmp = tmp->next;
	}
      sl->sp[col] = sp;
      col++;
    }
}

void last_col(t_select sl, int *row, int *col)
{
  t_list *tmp;

  tmp = sl.lc;
  while (tmp->next != NULL)
    {
      if (tmp->col == sl.max_col - 2 && tmp->next->col == 0)
	break ;
      tmp = tmp->next;
    }
  if (tmp->next == NULL)
    {
      *row = tmp->row;
      *col = tmp->col;
      return ;
    }
  *row = tmp->row - 1;
  *col = tmp->col + 1;
}

t_select init_list(int argc, char **argv)
{
  t_select list;
  struct winsize ws;

  if ((list.max_col = get_column(argc, &ws)) == 0)
    {
      list.lc = NULL;
      return (list);
    }
  list.max_row = ws.ws_row;
  list.col_len = ws.ws_col;
  list.argc = argc;
  list.lc = get_list(argc, argv, list.max_row, list.max_col);
  list.sp = (int*)malloc(sizeof(int) * list.max_col + 1);
  list.fd_tty = open("/dev/tty", O_RDWR);
  get_sp(&list);
  check_window_size(list);
  last_col(list, &list.l_row, &list.l_col);
  printf("%d %d\n", list.l_row, list.l_col);
  return (list);
}
/*
int main(int argc, char **argv)
{
  t_select sl;
  int i = 0;
  int max = 0;
  sl = init_list(argc - 1, argv + 1);
  print_list(sl);
}
*/
