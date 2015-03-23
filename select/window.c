#include "ft_select.h"

int check_window_size(t_select sl)
{
  int i;
  int line_len;
  char buffer[1];

  i = 0;
  line_len = 0;
  while (i < sl.max_col)
    {
      line_len += sl.sp[i] + 2;
      i++;
    }
  if (line_len > sl.col_len)
    {
      put_command("cl", 0);
      printf("window size too small.\n");
      return (0);
    }
  print_list(sl);
  return (1);
}

void window_resize(t_select *sl)
{
  struct winsize ws;
  t_list *tmp;
  t_pos size;

  sl->max_col = get_column(sl->argc, &ws);
  sl->max_row = ws.ws_row;
  sl->col_len = ws.ws_col;
  sl->lc = get_list(sl->argc, sl->lt, sl->max_row, sl->max_col);
  free(sl->sp);
  sl->sp = (int*)malloc(sizeof(int) * sl->max_col + 1);
  get_sp(sl);
  last_col(*sl, &(sl->l_row), &(sl->l_col));
  sl->enable = check_window_size(*sl);
}
