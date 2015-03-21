#include "ft_select.h"

void check_window_size(t_select sl)
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
      printf("window size too small.\n");
      while (1)
	read(0, buffer, 1);
    }
}

void window_resize(t_select *sl)
{
  struct winsize ws;
  t_list *tmp;
  t_pos size;

  sl->max_col = get_column(sl->argc, &ws);
  sl->max_row = ws.ws_row;
  sl->col_len = ws.ws_col;
  tmp = sl->lc;
  size.row = 0;
  while (col < sl->max_col)
    {
      size.col = 0;
      tmp->row = row;
      tmp->col = col;
      row++;
    }
      row++;
    }
}
