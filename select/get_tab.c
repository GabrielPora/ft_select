#include "ft_select.h"

void get_tab(t_list *tb[][], t_list *lc)
{
  int i;
  int j;

  i = 0;
  while (i < sl.max_col)
    {
      j = 0;
      while (*argv && j < sl.max_row)
	{
	  tb[]
	}
    }
}

void get_space_number(t_select *sl)
{
  int i;
  int j;
  int max;

  i = 0;
  while (i < sl->max_col)
    {
      j = 0;
      max = 0;
      while (sl->tb[i][j] && j < sl->max_row)
	{
	  if (sl->tb[i][j]->len > max)
	    max = sl->tb[i][j]->len;
	  j++;
	}
      sl->sp[i] = max;
      i++;
    }
}

t_list *get_lc(char **argv)
{
  t_list *tmp;
  t_list *lc;

  lc = NULL;
  while (*argv)
    {
      tmp = (t_list*)malloc(sizeof(t_list));
      tmp->name = *argv;
      tmp->len = strlen(*argv);
      tmp->indice = 0;
      tmp->next = NULL;
      add_end(&lc, tmp);
      argv++;
    }
  return (lc);
}

t_select get_line_colum(int argc, char **argv)
{
  t_select sl;
  struct winsize ws;

  if ((sl.max_col = get_column(argc, &ws)) == 0)
    {
      sl.tb = NULL;
      return (sl);
    }
  sl.max_row = ws.ws_row;
  sl.col_len = ws.ws_col;
  sl.argc = argc;
  sl.lc = get_lc(argv);
    //  get_tab(sl.tb, lc);
  printf("%d %d %d\n", sl.max_row, sl.col_len, sl.max_col);
  sl.sp = (int*)malloc(sizeof(int) * sl.col_len);
  get_space_number(&sl);
  return (sl);
}

int main(int argc, char **argv)
{
  t_select sl;
  int i = 0;
  int j = 0;
  int k;

  sl = get_line_colum(argc - 1, argv + 1);

}
